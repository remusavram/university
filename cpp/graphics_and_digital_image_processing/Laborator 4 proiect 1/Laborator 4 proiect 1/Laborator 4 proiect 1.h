// Laborator 4 proiect 1.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CLaborator4proiect1App:
// See Laborator 4 proiect 1.cpp for the implementation of this class
//

class CLaborator4proiect1App : public CWinApp
{
public:
	CLaborator4proiect1App();

// Overrides
	public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CLaborator4proiect1App theApp;