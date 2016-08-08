// Laborator 3 project 5.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CLaborator3project5App:
// See Laborator 3 project 5.cpp for the implementation of this class
//

class CLaborator3project5App : public CWinApp
{
public:
	CLaborator3project5App();

// Overrides
	public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CLaborator3project5App theApp;