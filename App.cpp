#include "App.hpp"  

wxIMPLEMENT_APP(App);

App::App()
{
	
}
	
App::~App()
{
    
}

bool App::OnInit() 
{
    m_frame1 = new Main();
    m_frame1->CenterOnScreen(wxBOTH | wxCENTER_ON_SCREEN);
    m_frame1->Show();

    return true;
}