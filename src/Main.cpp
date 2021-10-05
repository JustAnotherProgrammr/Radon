//
// Created by owen on 2021-07-10.
//

#include "Main.h"

wxString defaultDocumentName = "Untitled Document";
wxString exportPath;
wxString importPath;

wxBEGIN_EVENT_TABLE(Main, wxFrame)
                EVT_MENU(10002, Main::OnMenuOpen)
                EVT_MENU(10004, Main::OnMenuSave)
                EVT_MENU(10005, Main::OnMenuSaveAs)
                EVT_MENU(10006, Main::OnMenuExit)
                EVT_MENU(10007, Main::OnEditMode)
                EVT_MENU(10008, Main::OnViewMode)
wxEND_EVENT_TABLE()

Main::Main() : wxFrame(nullptr, wxID_ANY, "Radon - " + defaultDocumentName, wxPoint(0, 0), wxSize(800, 600))
{
    // Add private fonts
    wxFont InterEL = addPrivateFont("Inter-ExtraLight.ttf", "Inter-ExtraLight");
    wxFont InterBold = addPrivateFont("Inter-Bold.ttf", "Inter-Bold");
    wxFont InterReg = addPrivateFont("Inter-Regular.ttf", "Inter-Regular");

    // Add menu bar
    m_mbar = new wxMenuBar();
    this->SetMenuBar(m_mbar);
    // Populate menu bar
    wxMenu *menuFile = new wxMenu();
    menuFile->Append(10001, "New");
    menuFile->Append(10002, "Open");
    menuFile->Append(10003, "Open Recent");
    menuFile->Append(10004, "Save");
    menuFile->Append(10005, "Save As");
    menuFile->Append(10006, "Exit");
    m_mbar->Append(menuFile, "File");

    // Add toolbar
    m_toolbar = this->CreateToolBar();
    m_toolbar->AddTool(wxID_NEW, "New",
                     wxNullBitmap, wxNullBitmap, wxITEM_DROPDOWN,
                     "New file", "This is help for new file tool");
    m_modemenu = new wxMenu;
    m_modemenu->Append(10007, "&Edit Mode");
    m_modemenu->Append(10008, "&View Mode");
    m_toolbar->SetDropdownMenu(wxID_NEW, m_modemenu);
    m_toolbar->Realize();


    // Add main text box, font and grid layout
    m_tbx = new wxRichTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxVSCROLL | wxHSCROLL | wxRE_MULTILINE | wxBORDER_NONE | wxWANTS_CHARS);
    m_tbx->SetFont(InterReg);
    m_tbx->SetFilename(defaultDocumentName);
    wxGridSizer *m_gridSizer = new wxGridSizer(10, 10, 0, 0);
    m_gridSizer->Add(m_tbx, 1, wxEXPAND | wxALL);
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

#if RA_DEBUG
    std::cout << privfont << std::endl;
#endif

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
    loadFile();
    evt.Skip();
}

void Main::OnMenuSave(wxCommandEvent & evt)
{
    if (exportPath != wxEmptyString)
    {
        m_tbx->SaveFile(exportPath, wxRICHTEXT_TYPE_TEXT);
    } else if(importPath != wxEmptyString)
    {
        m_tbx->SaveFile(importPath, wxRICHTEXT_TYPE_TEXT);
#if RA_DEBUG
        if (importPath.EndsWith(".txt"))
        {
            std::cout << "ReSaved " << importPath << std::endl;
        } else
        {
            std::cout << "ReSaved " << importPath << ".txt" << std::endl;
        }
#endif
    } else
    {
        Main::saveFile();
    }
    evt.Skip();
}

void Main::OnMenuSaveAs(wxCommandEvent & evt)
{
    saveFile();
    evt.Skip();
}

void Main::OnMenuExit(wxCommandEvent & evt)
{
    Close();
    evt.Skip();
}

void Main::OnEditMode(wxCommandEvent &evt)
{
    m_tbx->SetEditable(true);
    m_tbx->GetCaret()->Show();
    evt.Skip();
}

void Main::OnViewMode(wxCommandEvent &evt)
{
    m_tbx->SetEditable(false);
    m_tbx->GetCaret()->Hide();
    evt.Skip();
}

void Main::loadFile()
{
    wxString importName;
    wxFileDialog fdlg(
            this, ("Open File"), "", "", "Txt Files (*.txt)|*.txt", wxFD_OPEN|wxFD_FILE_MUST_EXIST);
    fdlg.ShowModal();
    importPath = fdlg.GetPath();
    importName = fdlg.GetFilename();
    if (importPath != wxEmptyString) {
        m_tbx->LoadFile(importPath, wxRICHTEXT_TYPE_TEXT);
#if RA_DEBUG
        std::cout << "Loaded " << importPath << std::endl;
#endif
    }
    // Update the text box file name and wxFrame name
    m_tbx->SetFilename(importName);
    this->SetTitle("Radon - " + importName);
}

void Main::saveFile()
{
    wxString exportName;
    wxFileDialog fdlg(
            this, ("Save File"), "", "", "Txt Files (*.txt)|*.txt", wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
    fdlg.ShowModal();
    if (fdlg.GetPath() != wxEmptyString)
    {
        if (fdlg.GetPath().EndsWith(".txt"))
        {
            exportPath = fdlg.GetPath();
            exportName = fdlg.GetFilename();
        } else
        {
            exportPath = fdlg.GetPath() << ".txt";
            exportName = fdlg.GetFilename() << ".txt";
        }
        m_tbx->SaveFile(exportPath, wxRICHTEXT_TYPE_TEXT);
#if RA_DEBUG
        std::cout << "Saved " << exportPath << std::endl;
#endif
    }
    // Update the text box file name and wxFrame name
    m_tbx->SetFilename(exportName);
    this->SetTitle("Radon - " + exportName);
}

Main::~Main()
{

}