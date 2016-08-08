// OpenSaveColorDlg.h : header file
//

#pragma once


// COpenSaveColorDlg dialog
class COpenSaveColorDlg : public CDialog
{
// Construction
public:
	COpenSaveColorDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_OPENSAVECOLOR_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOpen();
public:
	afx_msg void OnBnClickedSave();
public:
	afx_msg void OnClose();
public:
	void AfisareImagine(void);
public:
	afx_msg void OnFisierOpen();
public:
	int Prel(void);
};
