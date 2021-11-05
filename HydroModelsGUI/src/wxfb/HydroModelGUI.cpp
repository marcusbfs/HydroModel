///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "HydroModelGUI.h"

///////////////////////////////////////////////////////////////////////////

MainFrame::MainFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style, const wxString& name ) : wxFrame( parent, id, title, pos, size, style, name )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetFont( wxFont( 16, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Arial") ) );

	wxBoxSizer* bSizerMainFrame;
	bSizerMainFrame = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizerFrameMain;
	bSizerFrameMain = new wxBoxSizer( wxVERTICAL );

	m_panelMain = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizerMainPanel;
	bSizerMainPanel = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizerPanelMain;
	bSizerPanelMain = new wxBoxSizer( wxVERTICAL );

	m_notebook = new wxNotebook( m_panelMain, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_panelEditor = new wxPanel( m_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );

	m_scintilla = new wxStyledTextCtrl( m_panelEditor, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, wxEmptyString );
	m_scintilla->SetUseTabs( false );
	m_scintilla->SetTabWidth( 4 );
	m_scintilla->SetIndent( 4 );
	m_scintilla->SetTabIndents( true );
	m_scintilla->SetBackSpaceUnIndents( true );
	m_scintilla->SetViewEOL( false );
	m_scintilla->SetViewWhiteSpace( false );
	m_scintilla->SetMarginWidth( 2, 0 );
	m_scintilla->SetIndentationGuides( true );
	m_scintilla->SetMarginType( 1, wxSTC_MARGIN_SYMBOL );
	m_scintilla->SetMarginMask( 1, wxSTC_MASK_FOLDERS );
	m_scintilla->SetMarginWidth( 1, 16);
	m_scintilla->SetMarginSensitive( 1, true );
	m_scintilla->SetProperty( wxT("fold"), wxT("1") );
	m_scintilla->SetFoldFlags( wxSTC_FOLDFLAG_LINEBEFORE_CONTRACTED | wxSTC_FOLDFLAG_LINEAFTER_CONTRACTED );
	m_scintilla->SetMarginType( 0, wxSTC_MARGIN_NUMBER );
	m_scintilla->SetMarginWidth( 0, m_scintilla->TextWidth( wxSTC_STYLE_LINENUMBER, wxT("_99999") ) );
	{
		wxFont font = wxFont( 16, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Arial") );
		m_scintilla->StyleSetFont( wxSTC_STYLE_DEFAULT, font );
	}
	m_scintilla->MarkerDefine( wxSTC_MARKNUM_FOLDER, wxSTC_MARK_BOXPLUS );
	m_scintilla->MarkerSetBackground( wxSTC_MARKNUM_FOLDER, wxColour( wxT("BLACK") ) );
	m_scintilla->MarkerSetForeground( wxSTC_MARKNUM_FOLDER, wxColour( wxT("WHITE") ) );
	m_scintilla->MarkerDefine( wxSTC_MARKNUM_FOLDEROPEN, wxSTC_MARK_BOXMINUS );
	m_scintilla->MarkerSetBackground( wxSTC_MARKNUM_FOLDEROPEN, wxColour( wxT("BLACK") ) );
	m_scintilla->MarkerSetForeground( wxSTC_MARKNUM_FOLDEROPEN, wxColour( wxT("WHITE") ) );
	m_scintilla->MarkerDefine( wxSTC_MARKNUM_FOLDERSUB, wxSTC_MARK_EMPTY );
	m_scintilla->MarkerDefine( wxSTC_MARKNUM_FOLDEREND, wxSTC_MARK_BOXPLUS );
	m_scintilla->MarkerSetBackground( wxSTC_MARKNUM_FOLDEREND, wxColour( wxT("BLACK") ) );
	m_scintilla->MarkerSetForeground( wxSTC_MARKNUM_FOLDEREND, wxColour( wxT("WHITE") ) );
	m_scintilla->MarkerDefine( wxSTC_MARKNUM_FOLDEROPENMID, wxSTC_MARK_BOXMINUS );
	m_scintilla->MarkerSetBackground( wxSTC_MARKNUM_FOLDEROPENMID, wxColour( wxT("BLACK") ) );
	m_scintilla->MarkerSetForeground( wxSTC_MARKNUM_FOLDEROPENMID, wxColour( wxT("WHITE") ) );
	m_scintilla->MarkerDefine( wxSTC_MARKNUM_FOLDERMIDTAIL, wxSTC_MARK_EMPTY );
	m_scintilla->MarkerDefine( wxSTC_MARKNUM_FOLDERTAIL, wxSTC_MARK_EMPTY );
	m_scintilla->SetSelBackground( true, wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHT ) );
	m_scintilla->SetSelForeground( true, wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHTTEXT ) );
	m_scintilla->SetFont( wxFont( 16, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Arial") ) );

	bSizer9->Add( m_scintilla, 1, wxEXPAND, 5 );


	bSizer10->Add( bSizer9, 1, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 0 );


	m_panelEditor->SetSizer( bSizer10 );
	m_panelEditor->Layout();
	bSizer10->Fit( m_panelEditor );
	m_notebook->AddPage( m_panelEditor, wxT("Editor"), true );
	m_panelFormattedOutput = new wxPanel( m_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizerFormattedPanelMain;
	bSizerFormattedPanelMain = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizerMainFormattedPanel;
	bSizerMainFormattedPanel = new wxBoxSizer( wxVERTICAL );

	m_gridFormattedOutput = new wxGrid( m_panelFormattedOutput, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	// Grid
	m_gridFormattedOutput->CreateGrid( 5, 5 );
	m_gridFormattedOutput->EnableEditing( false );
	m_gridFormattedOutput->EnableGridLines( true );
	m_gridFormattedOutput->EnableDragGridSize( false );
	m_gridFormattedOutput->SetMargins( 0, 0 );

	// Columns
	m_gridFormattedOutput->EnableDragColMove( false );
	m_gridFormattedOutput->EnableDragColSize( false );
	m_gridFormattedOutput->SetColLabelSize( 30 );
	m_gridFormattedOutput->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	m_gridFormattedOutput->EnableDragRowSize( false );
	m_gridFormattedOutput->SetRowLabelSize( 80 );
	m_gridFormattedOutput->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	m_gridFormattedOutput->SetDefaultCellTextColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );
	m_gridFormattedOutput->SetDefaultCellFont( wxFont( 14, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Arial") ) );
	m_gridFormattedOutput->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizerMainFormattedPanel->Add( m_gridFormattedOutput, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 0 );


	bSizerFormattedPanelMain->Add( bSizerMainFormattedPanel, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 0 );


	m_panelFormattedOutput->SetSizer( bSizerFormattedPanelMain );
	m_panelFormattedOutput->Layout();
	bSizerFormattedPanelMain->Fit( m_panelFormattedOutput );
	m_notebook->AddPage( m_panelFormattedOutput, wxT("a page"), false );
	m_panelOutput = new wxPanel( m_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxVERTICAL );

	m_scintillaOutput = new wxStyledTextCtrl( m_panelOutput, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, wxEmptyString );
	m_scintillaOutput->SetUseTabs( false );
	m_scintillaOutput->SetTabWidth( 4 );
	m_scintillaOutput->SetIndent( 4 );
	m_scintillaOutput->SetTabIndents( false );
	m_scintillaOutput->SetBackSpaceUnIndents( true );
	m_scintillaOutput->SetViewEOL( false );
	m_scintillaOutput->SetViewWhiteSpace( false );
	m_scintillaOutput->SetMarginWidth( 2, 0 );
	m_scintillaOutput->SetIndentationGuides( false );
	m_scintillaOutput->SetMarginType( 1, wxSTC_MARGIN_SYMBOL );
	m_scintillaOutput->SetMarginMask( 1, wxSTC_MASK_FOLDERS );
	m_scintillaOutput->SetMarginWidth( 1, 16);
	m_scintillaOutput->SetMarginSensitive( 1, true );
	m_scintillaOutput->SetProperty( wxT("fold"), wxT("1") );
	m_scintillaOutput->SetFoldFlags( wxSTC_FOLDFLAG_LINEBEFORE_CONTRACTED | wxSTC_FOLDFLAG_LINEAFTER_CONTRACTED );
	m_scintillaOutput->SetMarginType( 0, wxSTC_MARGIN_NUMBER );
	m_scintillaOutput->SetMarginWidth( 0, m_scintillaOutput->TextWidth( wxSTC_STYLE_LINENUMBER, wxT("_99999") ) );
	{
		wxFont font = wxFont( 16, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Arial") );
		m_scintillaOutput->StyleSetFont( wxSTC_STYLE_DEFAULT, font );
	}
	m_scintillaOutput->MarkerDefine( wxSTC_MARKNUM_FOLDER, wxSTC_MARK_BOXPLUS );
	m_scintillaOutput->MarkerSetBackground( wxSTC_MARKNUM_FOLDER, wxColour( wxT("BLACK") ) );
	m_scintillaOutput->MarkerSetForeground( wxSTC_MARKNUM_FOLDER, wxColour( wxT("WHITE") ) );
	m_scintillaOutput->MarkerDefine( wxSTC_MARKNUM_FOLDEROPEN, wxSTC_MARK_BOXMINUS );
	m_scintillaOutput->MarkerSetBackground( wxSTC_MARKNUM_FOLDEROPEN, wxColour( wxT("BLACK") ) );
	m_scintillaOutput->MarkerSetForeground( wxSTC_MARKNUM_FOLDEROPEN, wxColour( wxT("WHITE") ) );
	m_scintillaOutput->MarkerDefine( wxSTC_MARKNUM_FOLDERSUB, wxSTC_MARK_EMPTY );
	m_scintillaOutput->MarkerDefine( wxSTC_MARKNUM_FOLDEREND, wxSTC_MARK_BOXPLUS );
	m_scintillaOutput->MarkerSetBackground( wxSTC_MARKNUM_FOLDEREND, wxColour( wxT("BLACK") ) );
	m_scintillaOutput->MarkerSetForeground( wxSTC_MARKNUM_FOLDEREND, wxColour( wxT("WHITE") ) );
	m_scintillaOutput->MarkerDefine( wxSTC_MARKNUM_FOLDEROPENMID, wxSTC_MARK_BOXMINUS );
	m_scintillaOutput->MarkerSetBackground( wxSTC_MARKNUM_FOLDEROPENMID, wxColour( wxT("BLACK") ) );
	m_scintillaOutput->MarkerSetForeground( wxSTC_MARKNUM_FOLDEROPENMID, wxColour( wxT("WHITE") ) );
	m_scintillaOutput->MarkerDefine( wxSTC_MARKNUM_FOLDERMIDTAIL, wxSTC_MARK_EMPTY );
	m_scintillaOutput->MarkerDefine( wxSTC_MARKNUM_FOLDERTAIL, wxSTC_MARK_EMPTY );
	m_scintillaOutput->SetSelBackground( true, wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHT ) );
	m_scintillaOutput->SetSelForeground( true, wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHTTEXT ) );
	m_scintillaOutput->SetFont( wxFont( 16, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Arial") ) );

	bSizer11->Add( m_scintillaOutput, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer12->Add( bSizer11, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 0 );


	m_panelOutput->SetSizer( bSizer12 );
	m_panelOutput->Layout();
	bSizer12->Fit( m_panelOutput );
	m_notebook->AddPage( m_panelOutput, wxT("a page"), false );

	bSizerPanelMain->Add( m_notebook, 1, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 15 );


	bSizerMainPanel->Add( bSizerPanelMain, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 0 );

	wxBoxSizer* bSizer91;
	bSizer91 = new wxBoxSizer( wxVERTICAL );

	m_gauge1 = new wxGauge( m_panelMain, wxID_ANY, 100, wxDefaultPosition, wxDefaultSize, wxGA_HORIZONTAL );
	m_gauge1->SetValue( 0 );
	bSizer91->Add( m_gauge1, 0, wxALL|wxALIGN_RIGHT|wxEXPAND, 0 );


	bSizerMainPanel->Add( bSizer91, 0, wxEXPAND|wxALIGN_RIGHT, 5 );


	m_panelMain->SetSizer( bSizerMainPanel );
	m_panelMain->Layout();
	bSizerMainPanel->Fit( m_panelMain );
	bSizerFrameMain->Add( m_panelMain, 1, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 20 );


	bSizerMainFrame->Add( bSizerFrameMain, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 0 );


	this->SetSizer( bSizerMainFrame );
	this->Layout();
	m_statusBarMainFrame = this->CreateStatusBar( 2, wxSTB_SIZEGRIP, wxID_ANY );
	m_statusBarMainFrame->SetFont( wxFont( 9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Arial") ) );

	m_menubar = new wxMenuBar( 0 );
	m_menubar->SetFont( wxFont( 16, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Arial") ) );
	m_menubar->SetMinSize( wxSize( -1,20 ) );
	m_menubar->SetMaxSize( wxSize( -1,20 ) );

	m_menuFileHandler = new wxMenu();
	wxMenuItem* m_menuItemOpen;
	m_menuItemOpen = new wxMenuItem( m_menuFileHandler, wxID_ANY, wxString( wxT("Open") ) + wxT('\t') + wxT("ctrl-o"), wxT("Open a new file"), wxITEM_NORMAL );
	m_menuFileHandler->Append( m_menuItemOpen );

	wxMenuItem* m_menuItemSave;
	m_menuItemSave = new wxMenuItem( m_menuFileHandler, wxID_ANY, wxString( wxT("Save") ) + wxT('\t') + wxT("ctrl-s"), wxT("Save current file"), wxITEM_NORMAL );
	m_menuFileHandler->Append( m_menuItemSave );

	wxMenuItem* m_menuItemSaveAs;
	m_menuItemSaveAs = new wxMenuItem( m_menuFileHandler, wxID_ANY, wxString( wxT("Save As") ) + wxT('\t') + wxT("ctrl-shift-s"), wxT("Save as new file"), wxITEM_NORMAL );
	m_menuFileHandler->Append( m_menuItemSaveAs );

	m_menubar->Append( m_menuFileHandler, wxT("File") );

	m_menuRun = new wxMenu();
	wxMenuItem* m_menuItemRun;
	m_menuItemRun = new wxMenuItem( m_menuRun, wxID_ANY, wxString( wxT("Run") ) + wxT('\t') + wxT("ctrl-r"), wxT("Run calculations"), wxITEM_NORMAL );
	m_menuRun->Append( m_menuItemRun );

	m_menubar->Append( m_menuRun, wxT("Run") );

	this->SetMenuBar( m_menubar );

	this->Centre( wxBOTH );

	// Connect Events
	m_menuFileHandler->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OpenFileFromMenu ), this, m_menuItemOpen->GetId());
	m_menuFileHandler->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::SaveFileFromMenu ), this, m_menuItemSave->GetId());
	m_menuFileHandler->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::SaveAsFileFromMenu ), this, m_menuItemSaveAs->GetId());
	m_menuRun->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::RunFromMenu ), this, m_menuItemRun->GetId());
}

MainFrame::~MainFrame()
{
	// Disconnect Events

}
