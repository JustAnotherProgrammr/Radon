//
// Created by owen on 2021-07-10.
//

#ifndef RADON_MAIN_H
#define RADON_MAIN_H

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
    wxFont addPrivateFont(const wxString& pathName, const wxString& faceName);

    void OnMenuNew(wxCommandEvent &evt);
    void OnMenuOpen(wxCommandEvent &evt);
    void OnMenuSave(wxCommandEvent &evt);
    void OnMenuSaveAs(wxCommandEvent &evt);
    void OnMenuExit(wxCommandEvent &evt);
public:
    wxTextCtrl *m_tbx1 = nullptr;
    wxFont *m_font1 = nullptr;
    wxMenuBar *m_mbar = nullptr;

wxDECLARE_EVENT_TABLE();
};

#endif //RADON_MAIN_H
