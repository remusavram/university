// Laborator 1 tema 2.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CLaborator1tema2App:
// See Laborator 1 tema 2.cpp for the implementation of this class
//

class CLaborator1tema2App : public CWinApp
{
public:
	CLaborator1tema2App();

// Overrides
	public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CLaborator1tema2App theApp;