// Laborator 3 proiect 3.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CLaborator3proiect3App:
// See Laborator 3 proiect 3.cpp for the implementation of this class
//

class CLaborator3proiect3App : public CWinApp
{
public:
	CLaborator3proiect3App();

// Overrides
	public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CLaborator3proiect3App theApp;