// MyTreeView.cpp: файл реализации
//

#include "pch.h"
#include "1LB.h"
#include "CMyTreeView.h"
#include "1LBDoc.h"

// CMyTreeView

IMPLEMENT_DYNCREATE(CMyTreeView, CTreeView)

CMyTreeView::CMyTreeView()
{

}

CMyTreeView::~CMyTreeView()
{
}

BEGIN_MESSAGE_MAP(CMyTreeView, CTreeView)
	ON_WM_CREATE()
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()


// Диагностика CMyTreeView

#ifdef _DEBUG
void CMyTreeView::AssertValid() const
{
	CTreeView::AssertValid();
}

#ifndef _WIN32_WCE
void CMyTreeView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif
#endif //_DEBUG


// Обработчики сообщений CMyTreeView

void CMyTreeView::FillTree() {
	CTreeCtrl& tree = GetTreeCtrl();
	tree.DeleteAllItems();


	m_hColor = tree.InsertItem(L"Цвет", -1, -1, NULL, TVI_FIRST);
	
	m_hThickness = tree.InsertItem(L"Толщина", -1, -1, NULL, TVI_LAST);

	m_hThickness1 = tree.InsertItem(L"Тонкий", -1, -1, m_hThickness, TVI_FIRST);
	m_hThickness2 = tree.InsertItem(L"Средний", -1, -1, m_hThickness, TVI_LAST);
	m_hThickness3 = tree.InsertItem(L"Толстый", -1, -1, m_hThickness, TVI_LAST);

	m_hColor1 = tree.InsertItem(L"Красный", -1, -1, m_hColor, TVI_FIRST); 
	m_hColor2 = tree.InsertItem(L"Зеленый", -1, -1, m_hColor, TVI_LAST);
	m_hColor3 = tree.InsertItem(L"Синий", -1, -1, m_hColor, TVI_LAST);
	m_hColor4 = tree.InsertItem(L"Рандомный", -1, -1, m_hColor, TVI_LAST);
}

int CMyTreeView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	lpCreateStruct->style |= TVS_HASLINES | TVS_HASBUTTONS
		| TVS_LINESATROOT | TVS_SHOWSELALWAYS;// | TVS_CHECKBOXES;

	if (CTreeView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Добавьте специализированный код создания

	return 0;
}

void CMyTreeView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	CTreeCtrl& tree = GetTreeCtrl();
	CTreeView::OnLButtonDblClk(nFlags, point);

	CRect rc;
	tree.GetItemRect(m_hColor1, &rc, false);
	if (rc.PtInRect(point)) {
		for (int i = 0; i < m_pDoc->bubbles.size(); i++)
			m_pDoc->bubbles[i].SetColor(255,0,0);
	}

	tree.GetItemRect(m_hColor2, &rc, false);
	if (rc.PtInRect(point)) {
		for (int i = 0; i < m_pDoc->bubbles.size(); i++)
			m_pDoc->bubbles[i].SetColor(0, 255, 0);
	}

	tree.GetItemRect(m_hColor3, &rc, false);
	if (rc.PtInRect(point)) {
		for (int i = 0; i < m_pDoc->bubbles.size(); i++)
			m_pDoc->bubbles[i].SetColor(0, 0, 255);
	}

	tree.GetItemRect(m_hColor4, &rc, false);
	if (rc.PtInRect(point)) {
		for (int i = 0; i < m_pDoc->bubbles.size(); i++) {
			int randomR = rand() % 256;
			int randomG = rand() % 256;
			int randomB = rand() % 256;
			m_pDoc->bubbles[i].SetColor(randomR, randomG, randomB);
		}
	}

	tree.GetItemRect(m_hThickness1, &rc, false);
	if (rc.PtInRect(point)) {
		for (int i = 0; i < m_pDoc->bubbles.size(); i++)
			m_pDoc->bubbles[i].SetThickness(1);
	}

	tree.GetItemRect(m_hThickness2, &rc, false);
	if (rc.PtInRect(point)) {
		for (int i = 0; i < m_pDoc->bubbles.size(); i++)
			m_pDoc->bubbles[i].SetThickness(5);
	}

	tree.GetItemRect(m_hThickness3, &rc, false);
	if (rc.PtInRect(point)) {
		for (int i = 0; i < m_pDoc->bubbles.size(); i++)
			m_pDoc->bubbles[i].SetThickness(10);
			//m_pDoc->bubbles[i].SetThickness(m_pDoc->bubbles[i].m_r*2);
	}


}