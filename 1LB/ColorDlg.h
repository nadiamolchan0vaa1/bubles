#pragma once

//#include "1LBDoc.h"

class CMy1LBDoc;

// Диалоговое окно ColorDlg

class ColorDlg : public CDialog
{
	DECLARE_DYNAMIC(ColorDlg)

public:
	ColorDlg(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~ColorDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ColorDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	CMFCColorButton m_Color2;
	afx_msg void OnBnClickedOk();
	CMy1LBDoc* m_pDoc;
};
