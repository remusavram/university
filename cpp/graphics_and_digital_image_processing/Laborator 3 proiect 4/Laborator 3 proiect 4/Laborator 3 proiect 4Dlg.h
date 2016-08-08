// Laborator 3 proiect 4Dlg.h : header file
//

#pragma once


// CLaborator3proiect4Dlg dialog
class CLaborator3proiect4Dlg : public CDialog
{
// Construction
public:
	CLaborator3proiect4Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_LABORATOR3PROIECT4_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
};
