#pragma once

#include <wx/wx.h>
#include <wx/richtext/richtextctrl.h>
#include <wx/font.h>
#include <wx/stdpaths.h>
#include <wx/filename.h>

class Main : public wxFrame
{
	public:
		Main();
		~Main();
	private:
		wxFont addPrivateFont(wxString pathName, wxString faceName);

		void OnMenuNew(wxCommandEvent &evt);
		void OnMenuOpen(wxCommandEvent &evt);
		void OnMenuSave(wxCommandEvent &evt);
		void OnMenuSaveAs(wxCommandEvent &evt);
		void OnMenuExit(wxCommandEvent &evt);
	public:
		wxRichTextCtrl *m_tbx1 = nullptr;
		wxFont *m_font1 = nullptr;
		wxMenuBar *m_mbar = nullptr;

	wxDECLARE_EVENT_TABLE();
};