// Laborator 1 tema 2Dlg.h : header file
//

#pragma once


// CLaborator1tema2Dlg dialog
class CLaborator1tema2Dlg : public CDialog
{
// Construction
public:
	CLaborator1tema2Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_LABORATOR1TEMA2_DIALOG };

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
private:
	int* date;
	int nr_date;
	int maxim;
	COLORREF* culori;
};
