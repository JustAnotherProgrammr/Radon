#include "Main.hpp"  

Main::Main() : wxFrame(nullptr, wxID_ANY, "Radon - Untitled Document", wxPoint(0, 0), wxSize(800, 600))
{
	m_tbx1 = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE);
    wxGridSizer *m_gridSizer = new wxGridSizer(10, 10, 0, 0);
    m_gridSizer->Add(m_tbx1, 1, wxEXPAND | wxALL);
}
	
Main::~Main()
{

}