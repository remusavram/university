// Tema_cu_translatiiDlg.h : header file
//

#pragma once


// CTema_cu_translatiiDlg dialog
class CTema_cu_translatiiDlg : public CDialog
{
// Construction
public:
	CTema_cu_translatiiDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_TEMA_CU_TRANSLATII_DIALOG };

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
	CPoint *puncte;
	int nrpuncte;
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
private:
	bool press;
	int nrpunctevechi;
	bool pressreset;
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton6();
	void Translatie(int dx, int dy);
	void Rotatie(int unghi);
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
};
