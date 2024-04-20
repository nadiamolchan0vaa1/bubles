// ThicknessDlg.cpp: файл реализации
//
#pragma once

#include "pch.h"
#include "1LB.h"
#include "ThicknessDlg.h"
#include "afxdialogex.h"



// Диалоговое окно CThicknessDlg

IMPLEMENT_DYNAMIC(CThicknessDlg, CDialog)

CThicknessDlg::CThicknessDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIG_THICKNESS, pParent)
	, m_iValue(0)
{

}

CThicknessDlg::~CThicknessDlg()
{
}

void CThicknessDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_THICKNESS, m_iValue);
}


BEGIN_MESSAGE_MAP(CThicknessDlg, CDialog)
END_MESSAGE_MAP()


// Обработчики сообщений CThicknessDlg
