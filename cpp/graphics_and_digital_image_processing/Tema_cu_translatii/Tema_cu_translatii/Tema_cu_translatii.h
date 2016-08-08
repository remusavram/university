// Tema_cu_translatii.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CTema_cu_translatiiApp:
// See Tema_cu_translatii.cpp for the implementation of this class
//

class CTema_cu_translatiiApp : public CWinApp
{
public:
	CTema_cu_translatiiApp();

// Overrides
	public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CTema_cu_translatiiApp theApp;