
// Origin.h : main header file for the Origin application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// COriginApp:
// See Origin.cpp for the implementation of this class
//

class COriginApp : public CWinAppEx
{
public:
	COriginApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnTest();
};

extern COriginApp theApp;
