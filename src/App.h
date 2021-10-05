//
// Created by owen on 2021-07-10.
//

#ifndef RADON_APP_H
#define RADON_APP_H

#include <wx/wx.h>
#include "Main.h"

class App : public wxApp
{
public:
    App();
    ~App();
private:
    Main* m_frame1 = nullptr;
public:
    virtual bool OnInit();
};

#endif //RADON_APP_H