#pragma once

#include <wx/wx.h>

class Main : public wxFrame
{
	public:
		Main();
		~Main();
	public:
		wxTextCtrl *m_tbx1 = nullptr;
		wxMenuBar *m_mbar = nullptr;
	wxDECLARE_EVENT_TABLE();
};