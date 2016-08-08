// Laborator 4 proiect 1Dlg.h : header file
//

#pragma once


// CLaborator4proiect1Dlg dialog
class CLaborator4proiect1Dlg : public CDialog
{
// Construction
public:
	CLaborator4proiect1Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_LABORATOR4PROIECT1_DIALOG };

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
	int nrpuncte;
	CPoint *puncte;
	bool press;
	bool pressreset;
	int nrpunctevechi;
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};
