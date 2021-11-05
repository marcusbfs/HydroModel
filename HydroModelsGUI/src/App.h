#pragma once

#include <wx/wx.h>

#include "wxfb/HydroModelProjectMainFrame.h"

class App : public wxApp
{
public:
	App();
	~App();

public:
	virtual bool OnInit();

private:
	HydroModelProjectMainFrame* m_frame1 = nullptr;
};


