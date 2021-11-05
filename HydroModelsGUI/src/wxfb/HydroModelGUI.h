///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/stc/stc.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/grid.h>
#include <wx/notebook.h>
#include <wx/gauge.h>
#include <wx/statusbr.h>
#include <wx/menu.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MainFrame
///////////////////////////////////////////////////////////////////////////////
class MainFrame : public wxFrame
{
	private:

	protected:
		wxPanel* m_panelMain;
		wxNotebook* m_notebook;
		wxPanel* m_panelEditor;
		wxStyledTextCtrl* m_scintilla;
		wxPanel* m_panelFormattedOutput;
		wxGrid* m_gridFormattedOutput;
		wxPanel* m_panelOutput;
		wxStyledTextCtrl* m_scintillaOutput;
		wxGauge* m_gauge1;
		wxStatusBar* m_statusBarMainFrame;
		wxMenuBar* m_menubar;
		wxMenu* m_menuFileHandler;
		wxMenu* m_menuRun;

		// Virtual event handlers, overide them in your derived class
		virtual void OpenFileFromMenu( wxCommandEvent& event ) { event.Skip(); }
		virtual void SaveFileFromMenu( wxCommandEvent& event ) { event.Skip(); }
		virtual void SaveAsFileFromMenu( wxCommandEvent& event ) { event.Skip(); }
		virtual void RunFromMenu( wxCommandEvent& event ) { event.Skip(); }


	public:

		MainFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("HydroModel"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 935,756 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL, const wxString& name = wxT("HydroModel") );

		~MainFrame();

};

