#include "HydroModelProjectMainFrame.h"

#include <wx/msgdlg.h>
#include <wx/filedlg.h>
#include <wx/wfstream.h>
#include <wx/log.h> 
#include <wx/textfile.h>
#include <wx/txtstrm.h>

#include <thread>
#include <chrono>
#include <iomanip>
#include <sstream>

wxDEFINE_EVENT(EVNT_CALCULATION_DONE, wxCommandEvent);

HydroModelProjectMainFrame::HydroModelProjectMainFrame(wxWindow* parent)
	:
	MainFrame(parent)
{
	// initialize widgets
	this->initializeScintilla();
	this->initializeNotebookAndPanels();
	// subscribe observer
	this->m_hydromodels.subscribeObserver(dynamic_cast<HydroModelsObserver*>(this));
	// bind events
	this->Bind(EVNT_CALCULATION_DONE, &HydroModelProjectMainFrame::OnCalculationCompleted, this);
	this->Bind(wxEVT_CLOSE_WINDOW, &HydroModelProjectMainFrame::CloseMainProgram, this);
}

void HydroModelProjectMainFrame::OpenFileFromMenu(wxCommandEvent& event)
{
	// ...current content has not been saved...
	if (this->checkIfModified())
	{
		if (wxMessageBox(_("Current content has been modified! Proceed?"), _("Please confirm"),
			wxICON_QUESTION | wxYES_NO, this) == wxNO)
			return;
	}
	else if (!this->hasFlag(Saved))
	{
		if (wxMessageBox(_("Current content has not been saved! Proceed?"), _("Please confirm"),
			wxICON_QUESTION | wxYES_NO, this) == wxNO)
			return;
	}
	//else: proceed asking to the user the new file to open
	wxFileDialog
		openFileDialog(this, _("Open file"), "", "",
			"txt files (*.txt)|*.txt", wxFD_OPEN | wxFD_FILE_MUST_EXIST);
	if (openFileDialog.ShowModal() == wxID_CANCEL)
		return;     // the user changed idea...

	// proceed loading the file chosen by the user;
	// this can be done with e.g. wxWidgets input streams:
	wxFileInputStream input_stream(openFileDialog.GetPath());
	if (!input_stream.IsOk())
	{
		wxLogError("Cannot open file '%s'.", openFileDialog.GetPath());
		return;
	}
	// save file path
	this->m_currentFilePath = openFileDialog.GetPath();
	// load file
	this->loadFileFromPathToScintilla(m_currentFilePath);
	// go to editor panel
	m_notebook->SetSelection(0);
	m_scintilla->SetFocus();
	// clear output
	m_scintillaOutput->ClearAll();
	// display message
	this->setTimedStatusBarMessage("File opened", m_timeOfMessages);
	// propragate event
	event.Skip();
}

void HydroModelProjectMainFrame::SaveFileFromMenu(wxCommandEvent& event)
{
	// if file is alread saved or not modified, do nothing 
	if (!checkIfModified())
		return;

	// save content
	if (m_currentFilePath == "")
		this->SaveAsFileFromMenu(event);
	else
		this->saveScintillaContentToPath(this->m_currentFilePath);
	// propragate event
	event.Skip();
}

void HydroModelProjectMainFrame::SaveAsFileFromMenu(wxCommandEvent& event)
{
	wxFileDialog
		saveFileDialog(this, _("Save file"), "", "",
			"txt files (*.txt)|*.txt", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
	if (saveFileDialog.ShowModal() == wxID_CANCEL)
		return;     // the user changed idea...

	// save the current contents in the file;
	// this can be done with e.g. wxWidgets output streams:
	wxFileOutputStream output_stream(saveFileDialog.GetPath());
	if (!output_stream.IsOk())
	{
		wxLogError("Cannot save current contents in file '%s'.", saveFileDialog.GetPath());
		return;
	}
	// save current path
	this->m_currentFilePath = saveFileDialog.GetPath();
	// save content
	this->saveScintillaContentToPath(saveFileDialog.GetPath());
	// open these path now
	this->loadFileFromPathToScintilla(m_currentFilePath);
	// propragate event
	event.Skip();
}

void HydroModelProjectMainFrame::RunFromMenu(wxCommandEvent& event)
{
	// if there's already a calculation running, do nothing
	if (hasFlag(Calculating)) return;
	// do calculations
	doCalcWork();
	// propragate event
	event.Skip();
}

bool HydroModelProjectMainFrame::isThereContentOnTextEditor() const
{
	return !this->m_scintilla->IsEmpty();
}

bool HydroModelProjectMainFrame::loadFileFromPathToScintilla(const wxString& path)
{
	// get input stream
	wxFileInputStream input_stream(path);
	// get file content into scintilla
	wxTextInputStream text(input_stream, wxT("\x09"), wxConvUTF8);

	wxString file_content = "";

	// while content, read it and save it to variable
	while (input_stream.IsOk() && !input_stream.Eof())
	{
		file_content += text.ReadLine();
		file_content += "\n";
	}
	//clear scintilla content
	this->m_scintilla->ClearAll();
	// set new content
	this->m_scintilla->SetText(file_content);

	// set file name in content bar
	setStatusBarMessage("File: \"" + m_currentFilePath + "\"",
		m_statusBarMainFrame->GetFieldsCount() - 1);

	// save fiel content
	this->m_saved_content = file_content;

	return true;
}

void HydroModelProjectMainFrame::initializeScintilla()
{
	// set scintilla lexer (syntax highlighter)
	m_scintilla->StyleClearAll();
	m_scintilla->SetLexer(wxSTC_LEX_CPP);

	m_scintilla->SetKeyWords(0, wxT("MODEL VARIABLES PARAMETERS EQAUTIONS INPUT OUTPUT"));
	m_scintilla->SetKeyWords(0, wxT("HEAD VALUES MUL"));

	m_scintilla->StyleSetForeground(wxSTC_STYLE_LINENUMBER, wxColour(75, 75, 75));
	m_scintilla->StyleSetBackground(wxSTC_STYLE_LINENUMBER, wxColour(220, 220, 220));

	m_scintilla->SetWrapMode(wxSTC_WRAP_WORD);

	m_scintilla->StyleSetForeground(wxSTC_H_DOUBLESTRING, wxColour(255, 0, 0));
	m_scintilla->StyleSetForeground(wxSTC_H_SINGLESTRING, wxColour(255, 0, 0));
	m_scintilla->StyleSetForeground(wxSTC_H_ENTITY, wxColour(255, 0, 0));
	m_scintilla->StyleSetForeground(wxSTC_H_TAG, wxColour(0, 150, 0));
	m_scintilla->StyleSetForeground(wxSTC_H_TAGUNKNOWN, wxColour(0, 150, 0));
	m_scintilla->StyleSetForeground(wxSTC_H_ATTRIBUTE, wxColour(0, 0, 150));
	m_scintilla->StyleSetForeground(wxSTC_H_ATTRIBUTEUNKNOWN, wxColour(0, 0, 150));
	m_scintilla->StyleSetForeground(wxSTC_H_COMMENT, wxColour(150, 150, 150));

	m_scintilla->StyleSetForeground(wxSTC_STYLE_LINENUMBER, wxColour(75, 75, 75));
	m_scintilla->StyleSetBackground(wxSTC_STYLE_LINENUMBER, wxColour(220, 220, 220));

	// Properties found from http://www.scintilla.org/SciTEDoc.html
	m_scintilla->SetProperty(wxT("fold"), wxT("1"));
	m_scintilla->SetProperty(wxT("fold.comment"), wxT("1"));
	m_scintilla->SetProperty(wxT("fold.compact"), wxT("1"));

	wxColor grey(100, 100, 100);
	m_scintilla->MarkerDefine(wxSTC_MARKNUM_FOLDER, wxSTC_MARK_ARROW);
	m_scintilla->MarkerSetForeground(wxSTC_MARKNUM_FOLDER, grey);
	m_scintilla->MarkerSetBackground(wxSTC_MARKNUM_FOLDER, grey);

	m_scintilla->MarkerDefine(wxSTC_MARKNUM_FOLDEROPEN, wxSTC_MARK_ARROWDOWN);
	m_scintilla->MarkerSetForeground(wxSTC_MARKNUM_FOLDEROPEN, grey);
	m_scintilla->MarkerSetBackground(wxSTC_MARKNUM_FOLDEROPEN, grey);

	m_scintilla->MarkerDefine(wxSTC_MARKNUM_FOLDERSUB, wxSTC_MARK_EMPTY);
	m_scintilla->MarkerSetForeground(wxSTC_MARKNUM_FOLDERSUB, grey);
	m_scintilla->MarkerSetBackground(wxSTC_MARKNUM_FOLDERSUB, grey);

	m_scintilla->MarkerDefine(wxSTC_MARKNUM_FOLDEREND, wxSTC_MARK_ARROW);
	m_scintilla->MarkerSetForeground(wxSTC_MARKNUM_FOLDEREND, grey);
	m_scintilla->MarkerSetBackground(wxSTC_MARKNUM_FOLDEREND, _T("WHITE"));

	m_scintilla->MarkerDefine(wxSTC_MARKNUM_FOLDEROPENMID, wxSTC_MARK_ARROWDOWN);
	m_scintilla->MarkerSetForeground(wxSTC_MARKNUM_FOLDEROPENMID, grey);
	m_scintilla->MarkerSetBackground(wxSTC_MARKNUM_FOLDEROPENMID, _T("WHITE"));

	m_scintilla->MarkerDefine(wxSTC_MARKNUM_FOLDERMIDTAIL, wxSTC_MARK_EMPTY);
	m_scintilla->MarkerSetForeground(wxSTC_MARKNUM_FOLDERMIDTAIL, grey);
	m_scintilla->MarkerSetBackground(wxSTC_MARKNUM_FOLDERMIDTAIL, grey);

	m_scintilla->MarkerDefine(wxSTC_MARKNUM_FOLDERTAIL, wxSTC_MARK_EMPTY);
	m_scintilla->MarkerSetForeground(wxSTC_MARKNUM_FOLDERTAIL, grey);
	m_scintilla->MarkerSetBackground(wxSTC_MARKNUM_FOLDERTAIL, grey);
	// ---- End of code folding part

	m_scintilla->SetWrapMode(wxSTC_WRAP_WORD); // other choice is wxSCI_WRAP_NONE

	m_scintilla->StyleSetForeground(wxSTC_C_STRING, wxColour(150, 0, 0));
	m_scintilla->StyleSetForeground(wxSTC_C_PREPROCESSOR, wxColour(165, 105, 0));
	m_scintilla->StyleSetForeground(wxSTC_C_IDENTIFIER, wxColour(40, 0, 60));
	m_scintilla->StyleSetForeground(wxSTC_C_NUMBER, wxColour(0, 150, 0));
	m_scintilla->StyleSetForeground(wxSTC_C_CHARACTER, wxColour(150, 0, 0));
	m_scintilla->StyleSetForeground(wxSTC_C_WORD, wxColour(0, 0, 150));
	m_scintilla->StyleSetForeground(wxSTC_C_WORD2, wxColour(0, 150, 0));
	m_scintilla->StyleSetForeground(wxSTC_C_COMMENT, wxColour(150, 150, 150));
	m_scintilla->StyleSetForeground(wxSTC_C_COMMENTLINE, wxColour(150, 150, 150));
	m_scintilla->StyleSetForeground(wxSTC_C_COMMENTDOC, wxColour(150, 150, 150));
	m_scintilla->StyleSetForeground(wxSTC_C_COMMENTDOCKEYWORD, wxColour(0, 0, 200));
	m_scintilla->StyleSetForeground(wxSTC_C_COMMENTDOCKEYWORDERROR, wxColour(0, 0, 200));
	m_scintilla->StyleSetBold(wxSTC_C_WORD, true);
	m_scintilla->StyleSetBold(wxSTC_C_WORD2, true);
	m_scintilla->StyleSetBold(wxSTC_C_COMMENTDOCKEYWORD, true);

	// a sample list of keywords, I haven't included them all to keep it short...
	m_scintilla->SetKeyWords(0, wxT("return for while break continue"));
	m_scintilla->SetKeyWords(1, wxT("const int float void char double"));
}

bool HydroModelProjectMainFrame::saveScintillaContentToPath(const wxString& path)
{
	// output stream
	wxFileOutputStream output_stream(path);
	// transfer scintilla content to output stream
	m_saved_content = m_scintilla->GetText();
	// write to output stream
	output_stream.Write(m_saved_content.c_str(), m_saved_content.Length());
	// close file
	output_stream.Close();
	// put status to saved
	this->setFlag(Saved);
	// remove status of modified
	this->removeFlag(Modified);
	// set message informing that it was saved
	this->setTimedStatusBarMessage("File saved", m_timeOfMessages);
	return true;
}

void HydroModelProjectMainFrame::setOutputContent()
{
	// allow write
	m_scintillaOutput->SetReadOnly(false);
	// clear all and put content
	m_scintillaOutput->ClearAll();
	m_scintillaOutput->SetText(m_output_content);
	// disable write
	m_scintillaOutput->SetReadOnly(true);
}

void HydroModelProjectMainFrame::update()
{
	// remove Calculating flag
	this->removeFlag(Calculating);
	// stop pulsing
	m_gauge1->SetValue(0);
	setTimedStatusBarMessage("Calculation completed", m_timeOfMessages);
	// send evnt
	wxCommandEvent event(EVNT_CALCULATION_DONE);
	this->QueueEvent(event.Clone());
}

void HydroModelProjectMainFrame::updateFormattedOutput()
{
	// only one can change
	const std::lock_guard<std::mutex> lock(m_mutex_output);

	// set formatted output
	// get data
	const auto& models = m_hydromodels.getModelsName();
	const auto& headers = m_hydromodels.getOutputHeaders();
	// reset grid
	m_gridFormattedOutput->DeleteRows(0, m_gridFormattedOutput->GetNumberRows());
	m_gridFormattedOutput->DeleteCols(0, m_gridFormattedOutput->GetNumberCols());
	// create new grid
	const auto& grid_cols = headers.size();
	const auto& num_hydros = m_hydromodels.getModelOutputValues(models[0])[headers[0]].size();
	const auto& grid_rows = models.size() * (3 + num_hydros);
	m_gridFormattedOutput->AppendRows(grid_rows);
	m_gridFormattedOutput->AppendCols(grid_cols);
	// populate grid
	size_t i = 0;
	for (const auto& model : models) {
		// model name cell
		auto model_font = m_gridFormattedOutput->GetCellFont(i, 0);
		m_gridFormattedOutput->SetCellFont(i, 0, model_font.MakeBold().MakeItalic());
		// merge cells
		m_gridFormattedOutput->SetCellSize(i, 0, 1, m_gridFormattedOutput->GetNumberCols());
		// align
		m_gridFormattedOutput->SetCellAlignment(i, 0, wxALIGN_LEFT, wxALIGN_CENTER_VERTICAL);
		// put name
		m_gridFormattedOutput->SetCellValue(i++, 0, model);
		// begin populate headers and data
		size_t  j = 0;
		size_t  k = 1;
		for (const auto& header : headers) {
			auto header_font = m_gridFormattedOutput->GetCellFont(i, j);
			// format
			m_gridFormattedOutput->SetCellAlignment(i, j, wxALIGN_RIGHT, wxALIGN_CENTER_VERTICAL);
			m_gridFormattedOutput->SetCellFont(i, j, header_font.MakeBold());
			m_gridFormattedOutput->SetCellValue(i, j, header);
			k = 1;
			auto header_values = m_hydromodels.getModelOutputValues(model);
			const auto& values = header_values[header];
			for (const auto& value : values) {
				m_gridFormattedOutput->SetCellAlignment(i + k, j, wxALIGN_RIGHT, wxALIGN_CENTER_VERTICAL);
				m_gridFormattedOutput->SetCellValue(i + k++, j, doubleToStr(value));
			}
			j++;
		}
		i += k + 1;
	}
	// autosize cols and rows
	m_gridFormattedOutput->AutoSize();
	// refresh to enable scrollbar
	m_panelFormattedOutput->Layout();
	// set focus
	m_notebook->SetSelection(1);
	// set output content (raw content)
	m_output_content = m_hydromodels.getStandardFormattedString();
	setOutputContent();
	return;
}

std::string HydroModelProjectMainFrame::doubleToStr(const double& value) const
{
	constexpr size_t precision = 8;
	std::stringstream ss;
	ss << std::setprecision(precision) << value;
	return ss.str();
}

void HydroModelProjectMainFrame::OnCalculationCompleted(wxCommandEvent& event)
{
	this->updateFormattedOutput();
	event.Skip();
}

void HydroModelProjectMainFrame::CloseMainProgram(wxCloseEvent& event)
{
	if (this->checkIfModified())
	{
		if (wxMessageBox(_("Current content has been modified! Proceed?"), _("Please confirm"),
			wxICON_QUESTION | wxYES_NO, this) == wxNO)
			return;
	}
	event.Skip();
}

void HydroModelProjectMainFrame::setStatusBarMessage(const wxString& msg, const int& field) {
	const std::lock_guard<std::mutex> lock(m_mutex_statusbar);
	this->m_statusBarMainFrame->SetStatusText(msg, field);
}

void HydroModelProjectMainFrame::setTimedStatusBarMessage(const wxString& msg, const int& time)
{
	auto lambda_fun = [&, this, msg, time]() {
		setStatusBarMessage(msg, 0);
		std::this_thread::sleep_for(std::chrono::milliseconds(time));
		setStatusBarMessage("", 0);
	};
	std::thread worker(lambda_fun);
	worker.detach();
}

void HydroModelProjectMainFrame::initializeNotebookAndPanels()
{
	// set tabs names
	m_notebook->SetPageText(0, "Editor");
	m_notebook->SetPageText(1, "Formatted output");
	m_notebook->SetPageText(2, "Raw output");
	// set output to read only
	m_scintillaOutput->SetReadOnly(true);
	// initialize formmatted output grid
	const std::lock_guard<std::mutex> lock(m_mutex_output);
	m_gridFormattedOutput->HideColLabels();
	m_gridFormattedOutput->HideRowLabels();
	m_gridFormattedOutput->DeleteRows(0, m_gridFormattedOutput->GetNumberRows());
	m_gridFormattedOutput->DeleteCols(0, m_gridFormattedOutput->GetNumberCols());
	// select first tab
	m_notebook->SetSelection(0);
}

void HydroModelProjectMainFrame::setFlag(const FLAGTYPE& flag)
{
	const std::lock_guard<std::mutex> lock(m_mutex_flags);
	m_flags |= flag;
}

void HydroModelProjectMainFrame::removeFlag(const FLAGTYPE& flag)
{
	const std::lock_guard<std::mutex> lock(m_mutex_flags);
	m_flags &= ~flag;
}

bool HydroModelProjectMainFrame::hasFlag(const FLAGTYPE& flag) const
{
	return Empty != (m_flags & flag);
}

bool HydroModelProjectMainFrame::checkIfModified()
{
	if (m_scintilla->GetText() != m_saved_content) {
		this->setFlag(Modified);
		return true;
	}
	this->removeFlag(Modified);
	return false;
}

void HydroModelProjectMainFrame::doCalcWork()
{
	// set flag to Calculating
	this->setFlag(Calculating);
	// start pulsing
	m_gauge1->Pulse();
	// set message
	this->setStatusBarMessage("Calculating...", 0);
	// updates file path on model
	this->m_hydromodels.setInputFile(m_currentFilePath.ToStdString());

	auto worker_lambda = [&, this]() {
		// m_hydromodels will notify observers when calculation is finished
		this->m_hydromodels.calculate();
	};

	std::thread worker(worker_lambda);
	worker.detach();
}
