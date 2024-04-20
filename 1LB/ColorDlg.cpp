// ColorDlg.cpp: файл реализации
//


#include "pch.h"
#include "1LB.h"
#include "ColorDlg.h"
#include "afxdialogex.h"
#include "1LBDoc.h"

// Диалоговое окно ColorDlg

IMPLEMENT_DYNAMIC(ColorDlg, CDialog)

ColorDlg::ColorDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_ColorDlg, pParent)
{
	m_pDoc = nullptr;
}

ColorDlg::~ColorDlg()
{
}

void ColorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON1, m_Color2);
}


BEGIN_MESSAGE_MAP(ColorDlg, CDialog)
	ON_BN_CLICKED(IDOK, &ColorDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// Обработчики сообщений ColorDlg


void ColorDlg::OnBnClickedOk()
{
	// TODO: добавьте свой код обработчика уведомлений
	CDialog::OnOK();
	if (m_pDoc != nullptr)
		m_pDoc->m_Color = m_Color2.GetColor();
}
