#include "Main.hpp"  

wxBEGIN_EVENT_TABLE(Main, wxFrame)

wxEND_EVENT_TABLE()

Main::Main() : wxFrame(nullptr, wxID_ANY, "Radon - Untitled Document", wxPoint(0, 0), wxSize(800, 600))
{
    // Add menu bar
    m_mbar = new wxMenuBar();
    this->SetMenuBar(m_mbar);

    // Menu bar buttons
    wxMenu *menuFile = new wxMenu();
    menuFile->Append(10002, "Open");
    menuFile->Append(10003, "Open Recent");
    menuFile->Append(10004, "Save");
    menuFile->Append(10005, "Save As");
    menuFile->Append(10006, "Exit");

    m_mbar->Append(menuFile, "File");

    // Add main text box and grid layout
	m_tbx1 = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE);
    wxGridSizer *m_gridSizer = new wxGridSizer(10, 10, 0, 0);
    m_gridSizer->Add(m_tbx1, 1, wxEXPAND | wxALL);
}
	
Main::~Main()
{

}