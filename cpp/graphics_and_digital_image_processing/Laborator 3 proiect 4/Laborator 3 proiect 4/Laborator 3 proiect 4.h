// Laborator 3 proiect 4.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CLaborator3proiect4App:
// See Laborator 3 proiect 4.cpp for the implementation of this class
//

class CLaborator3proiect4App : public CWinApp
{
public:
	CLaborator3proiect4App();

// Overrides
	public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CLaborator3proiect4App theApp;