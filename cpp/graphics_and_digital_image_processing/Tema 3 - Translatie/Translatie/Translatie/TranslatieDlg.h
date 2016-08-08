// TranslatieDlg.h : header file
//

#pragma once
#include "atltypes.h"


// CTranslatieDlg dialog
class CTranslatieDlg : public CDialog
{
// Construction
public:
	CTranslatieDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_TRANSLATIE_DIALOG };

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
	int nr_puncte;
public:
	CPoint *puncte;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
private:
	bool presetpoly;
	bool pcreatepoly;
	int punctevechi;
public:
	afx_msg void OnBnClickedButton2();
	afx_msg void OnEnChangeEdit5();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	void Translatie(int dx, int dy);
	void Rotatie(int unghi);
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	
private:
	CPoint cg;
public:
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton8();
	void Scalare(double sx, double sy);
};
