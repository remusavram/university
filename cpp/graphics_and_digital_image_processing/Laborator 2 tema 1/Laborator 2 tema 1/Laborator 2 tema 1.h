// Laborator 2 tema 1.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CLaborator2tema1App:
// See Laborator 2 tema 1.cpp for the implementation of this class
//

class CLaborator2tema1App : public CWinApp
{
public:
	CLaborator2tema1App();

// Overrides
	public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CLaborator2tema1App theApp;