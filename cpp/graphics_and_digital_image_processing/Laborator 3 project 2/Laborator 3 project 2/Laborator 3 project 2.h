// Laborator 3 project 2.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CLaborator3project2App:
// See Laborator 3 project 2.cpp for the implementation of this class
//

class CLaborator3project2App : public CWinApp
{
public:
	CLaborator3project2App();

// Overrides
	public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CLaborator3project2App theApp;