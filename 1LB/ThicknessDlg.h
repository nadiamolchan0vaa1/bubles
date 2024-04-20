#pragma once
#include "1LBDoc.h"

class CMy1LBDoc;
// Диалоговое окно CThicknessDlg

class CThicknessDlg : public CDialog
{
	DECLARE_DYNAMIC(CThicknessDlg)

public:
	CThicknessDlg(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~CThicknessDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIG_THICKNESS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	int m_iValue;
	CMy1LBDoc* m_pDoc;
};
