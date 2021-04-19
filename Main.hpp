#pragma once

#include <wx/wx.h>

class Main : public wxFrame
{
	public:
		Main();
		~Main();
	public:
		wxTextCtrl *m_tbx1 = nullptr;
};