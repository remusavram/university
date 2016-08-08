// Laborator2Dlg.h : header file
//

#pragma once


// CLaborator2Dlg dialog
class CLaborator2Dlg : public CDialog
{
// Construction
public:
	CLaborator2Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_LABORATOR2_DIALOG };

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
	int *vect;
private:
	int nrvar;
	int maxim;
	COLORREF *culori;
};
