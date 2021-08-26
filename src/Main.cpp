//
// Created by owen on 2021-07-10.
//

#include "Main.h"

wxBEGIN_EVENT_TABLE(Main, wxFrame)
                EVT_MENU(10006, Main::OnMenuExit)
wxEND_EVENT_TABLE()

Main::Main() : wxFrame(nullptr, wxID_ANY, "Radon - Untitled Document", wxPoint(0, 0), wxSize(800, 600))
{
    // Add private fonts
    wxFont InterEL = addPrivateFont("Inter-ExtraLight.ttf", "Inter-ExtraLight");
    wxFont InterBold = addPrivateFont("Inter-Bold.ttf", "Inter-Bold");
    wxFont InterReg = addPrivateFont("Inter-Regular.ttf", "Inter-Regular");

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
    m_tbx1 = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE);

    m_tbx1->SetFont(InterReg);

    wxGridSizer *m_gridSizer = new wxGridSizer(10, 10, 0, 0);
    m_gridSizer->Add(m_tbx1, 1, wxEXPAND | wxALL);
}

wxFont Main::addPrivateFont(const wxString& fileName, const wxString& faceName)
{
    // Inter-ExtraLight.ttf
    wxString privfont;
    privfont << wxStandardPaths::Get().GetExecutablePath();
    wxFileName fn = wxFileName::DirName(privfont);
    fn.RemoveLastDir();
    fn.RemoveLastDir();
    privfont = fn.GetFullPath();

    privfont << "font/" + fileName;

    std::cout << privfont << std::endl;

    if (!wxFont::AddPrivateFont(privfont)) {
        wxLogMessage("Could not load private fonts");
        Close();
    }

    wxFont font(wxFontInfo(30).FaceName(faceName));

    return font;
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
