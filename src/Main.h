//
// Created by owen on 2021-07-10.
//

#pragma once

#include <wx/wx.h>
#include <wx/richtext/richtextctrl.h>
#include <wx/font.h>
#include <wx/stdpaths.h>
#include <wx/filename.h>
#include <wx/richtext/richtextctrl.h>
#include <wx/filedlg.h>

class Main : public wxFrame
{
public:
    Main();
    ~Main();
private:
    void OnMenuNew(wxCommandEvent &evt);
    void OnMenuOpen(wxCommandEvent &evt);
    void OnMenuSave(wxCommandEvent &evt);
    void OnMenuSaveAs(wxCommandEvent &evt);
    void OnMenuExit(wxCommandEvent &evt);
    void OnEditMode(wxCommandEvent &evt);
    void OnViewMode(wxCommandEvent &evt);
public:
    wxFont addPrivateFont(const wxString& pathName, const wxString& faceName);
    void loadFile();
    void saveFile(bool addDialog);
    void updateTitle();
private:
    wxRichTextCtrl *m_tbx = nullptr;
    wxMenuBar *m_mbar = nullptr;
    wxToolBar *m_toolbar = nullptr;
    wxMenu *m_modemenu = nullptr;
wxDECLARE_EVENT_TABLE();
};