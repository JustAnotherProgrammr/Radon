#include "Main.hpp"

wxBEGIN_EVENT_TABLE(Main, wxFrame)
    EVT_MENU(10006, Main::OnMenuExit)
wxEND_EVENT_TABLE()

Main::Main() : wxFrame(nullptr, wxID_ANY, "Radon - Untitled Document", wxPoint(0, 0), wxSize(800, 600))
{
    // Add private fonts

        // Inter-ExtraLight.ttf
        wxString privfont;
        privfont << wxStandardPaths::Get().GetExecutablePath();
        wxFileName fn = wxFileName::DirName(privfont);
        fn.RemoveLastDir();
        privfont = fn.GetFullPath();

        privfont << "font/Inter-ExtraLight.ttf";
    
        wxPrintf(privfont + "\n");

        if (!wxFont::AddPrivateFont(privfont)) {
            wxLogMessage("Could not load private fonts");
            Close();
        }

        wxFont InterBold(wxFontInfo(30).FaceName("Inter"));
    
    // Add menu bar
    m_mbar = new wxMenuBar();
    this->SetMenuBar(m_mbar);

    // Menu bar buttons
    wxMenu *menuFile = new wxMenu();
    menuFile->Append(10001, "New");
    menuFile->Append(10002, "Open");
    menuFile->Append(10003, "Open Recent");
    menuFile->Append(10004, "Save");
    menuFile->Append(10005, "Save As");
    menuFile->Append(10006, "Exit");

    m_mbar->Append(menuFile, "File");

    // Add main text box, font and grid layout
	m_tbx1 = new wxRichTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE);

    //m_font1 = new wxFont(12, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
    m_tbx1->SetFont(InterBold);
    
    wxGridSizer *m_gridSizer = new wxGridSizer(10, 10, 0, 0);
    m_gridSizer->Add(m_tbx1, 1, wxEXPAND | wxALL);
}

void Main::OnMenuNew(wxCommandEvent & evt) 
{

}

void Main::OnMenuOpen(wxCommandEvent & evt) 
{

}

void Main::OnMenuSave(wxCommandEvent & evt) 
{

}

void Main::OnMenuSaveAs(wxCommandEvent & evt) 
{

}

void Main::OnMenuExit(wxCommandEvent & evt) 
{
    Close();
    evt.Skip();
}

Main::~Main()
{

}