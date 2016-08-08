// Laborator 2 tema 1Dlg.h : header file
//

#pragma once


// CLaborator2tema1Dlg dialog
class CLaborator2tema1Dlg : public CDialog
{
// Construction
public:
	CLaborator2tema1Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_LABORATOR2TEMA1_DIALOG };

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
public:
//	afx_msg void OnMButtonDown(UINT nFlags, CPoint point);
private:
	int* puncte;
public:
	int nrpuncte;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};
