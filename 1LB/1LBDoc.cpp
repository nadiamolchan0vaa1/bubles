
// 1LBDoc.cpp: реализация класса CMy1LBDoc 
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "1LB.h"
#include "1LBView.h"
#endif

#include "ThicknessDlg.h"
//#include "1LBDoc.h"

#include <propkey.h>

#include <ctime>

#include <iostream>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMy1LBDoc

IMPLEMENT_DYNCREATE(CMy1LBDoc, CDocument)

BEGIN_MESSAGE_MAP(CMy1LBDoc, CDocument)
	ON_COMMAND(ID_SETTINGS_COLOR, &CMy1LBDoc::OnSettingsColor)
	ON_COMMAND(ID_SETTINGS_THICKNESS, &CMy1LBDoc::OnSettingsThickness)
	ON_UPDATE_COMMAND_UI(ID_SETTINGS_COLOR, &CMy1LBDoc::OnUpdateSettingsColor)
	ON_COMMAND(ID_SETTINGS_VISIBILLTY, &CMy1LBDoc::OnSettingsVisibillty)
	ON_UPDATE_COMMAND_UI(ID_SETTINGS_VISIBILLTY, &CMy1LBDoc::OnUpdateSettingsVisibillty)
	ON_COMMAND(ID_VISIBILITY, &CMy1LBDoc::OnVisibility)
END_MESSAGE_MAP()

CMyCircle::CMyCircle()
{
	m_x = 0;
	m_y = 0;
	m_r = 0;
	deltaX = 0;
	deltaY = 0;
	thickness = 0;
	r = 0;
	g = 0;
	b = 0;
}

void CMyCircle::Сreate(int height, int width) {
	m_r = 10 + rand() % 100;
	m_y = m_r + rand() % (height - 2 * m_r);
	m_x = m_r + rand() % (width - 2 * m_r);
	deltaX = -10 + rand() % 21;
	deltaY = -10 + rand() % 21;
}

void CMyCircle::Draw(CDC* pDC) {
	srand(time(NULL));
	CPen pen(PS_SOLID, thickness, RGB(r, g, b));
	CPen* pOldPen = pDC->SelectObject(&pen);
	pDC->MoveTo(m_x + m_r, m_y);
	pDC->AngleArc(m_x, m_y, m_r, 0, 360);
	/*CBrush brush(RGB(0, 255, 0));

	CClientDC dc(this);
	CBrush brush = RGB(255, 255, 0);
	CBrush* pbr = dc.SelectObject(&brush);
	dc.SelectObject(&brush);
}*/
}

void CMyCircle::Traffic(int height, int width) {
	m_x += deltaX;
	m_y += deltaY;
	if (m_x + m_r >= width){
		deltaX *= -1;
		m_x = width - m_r - 1;
	}
	if (m_y + m_r >= height){
		deltaY *= -1;
		m_y = height - m_r - 1;
	}
	if (m_x - m_r <= 0) {
		deltaX *= -1;
		m_x = 0 + m_r + 1;
	}
	if (m_y - m_r <= 0) {
		deltaY *= -1;
		m_y = 0 + m_r + 1;
	}

}

void CMyCircle::Bump(CMyCircle& circle) {
	double v1x = deltaX;
	double v1y = deltaY;
	double v2x = circle.deltaX;
	double v2y = circle.deltaY;

	double x1 = m_x;
	double y1 = m_y;
	double x2 = circle.m_x;
	double y2 = circle.m_y;
	double distance = sqrt(pow(m_x - circle.m_x, 2) + pow(m_y - circle.m_y, 2));
	if (distance < m_r + circle.m_r) {
		double dot = (v1x - v2x) * (x1 - x2) + (v1y - v2y) * (y1 - y2);
		double denom1 = (pow(x1 - x2, 2) + pow(y1 - y2, 2));
		double denom2 = (pow(x2 - x1, 2) + pow(y2 - y1, 2));
		double w1x = v1x - dot * (x1 - x2) / denom1;
		double w1y = v1y - dot * (y1 - y2) / denom1;

		double w2x = v2x - dot * (x2 - x1) / denom2;
		double w2y = v2y - dot * (y2 - y1) / denom2;

		deltaX = w1x;
		deltaY = w1y;
		circle.deltaX = w2x;
		circle.deltaY = w2y;

		double k = 10;
		double xx2 = (x2 - x1) / k + x2;
		double yy2 = (y2 - y1) / k + y2;
		double xx1 = (x1 - x2) / k + x1;
		double yy1 = (y1 - y2) / k + y1;
		m_x = xx1;
		m_y = yy1;
		circle.m_x = xx2;
		circle.m_y = yy2;
	}
}

void CMyCircle::SetColor(int r, int g, int b) {
	this->r = r;
	this->g = g;
	this->b = b;
}

void CMyCircle::SetThickness(int thickness) {
	this->thickness = thickness;
}

// Создание или уничтожение CMy1LBDoc

CMy1LBDoc::CMy1LBDoc() noexcept 
{
	// TODO: добавьте код для одноразового вызова конструктора
	srand(time(NULL));
	m_Iversion = 2;
	
	
}

CMy1LBDoc::~CMy1LBDoc()
{
}

BOOL CMy1LBDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: добавьте код повторной инициализации
	// (Документы SDI будут повторно использовать этот документ)
	m_pTreeView->FillTree();

	/*CWnd* MainWnd = AfxGetMainWnd();

	if (MainWnd)
	{

		m_pTreeView = (CMyTreeView*)((CMy1LBView*)MainWnd)->m_so.GetPane(0, 0);
		m_pView = (CSDIAppView*)((CMainFrame*)MainWnd)->m_wndSplitter.GetPane(0, 1);
		m_pTreeView->m_pDoc = this;
	}
	m_pTreeView->FillTree();
	m_bLine1 = m_bLine2 = m_bCircle = false;*/



	return TRUE;
}




// Сериализация CMy1LBDoc

void CMy1LBDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: добавьте код сохранения
	}
	else
	{
		// TODO: добавьте код загрузки
	}
}

#ifdef SHARED_HANDLERS

// Поддержка для эскизов
void CMy1LBDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Измените этот код для отображения данных документа
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Поддержка обработчиков поиска
void CMy1LBDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Задание содержимого поиска из данных документа.
	// Части содержимого должны разделяться точкой с запятой ";"

	// Например:  strSearchContent = _T("точка;прямоугольник;круг;объект ole;");
	SetSearchContent(strSearchContent);
}

void CMy1LBDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// Диагностика CMy1LBDoc

#ifdef _DEBUG
void CMy1LBDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMy1LBDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// Команды CMy1LBDoc


void CMy1LBDoc::OnSettingsColor()
{
	// TODO: добавьте свой код обработчика команд
	
	if (!m_ColorDlg) {
		m_ColorDlg.Create(IDD_ColorDlg, AfxGetMainWnd());
	}
	m_ColorDlg.m_pDoc = this;
	//m_ColorDlg.m_Color2.SetColor(m_Color);
	m_ColorDlg.m_Color2.SetColor(bubbles[0].myColor);

	m_ColorDlg.ShowWindow(SW_SHOW);

	/*for (int i = 0; i < bubbles.size(); i++) {
		bubbles[i].SetColor(GetRValue(m_Color), GetGValue(m_Color),GetBValue(m_Color));
	}*/
}


void CMy1LBDoc::OnSettingsThickness()
{
	// TODO: добавьте свой код обработчика команд
	CThicknessDlg dlg;
	dlg.m_iValue = m_Thickness;

	if (dlg.DoModal() == IDOK) {
		m_Thickness = dlg.m_iValue;
	}
	m_Thickness = dlg.m_iValue;
	
	for (int i = 0; i < bubbles.size(); i++) {
		bubbles[i].SetThickness(m_Thickness);
	}
}


void CMy1LBDoc::OnUpdateSettingsColor(CCmdUI* pCmdUI)
{
	// TODO: добавьте свой код обработчика ИП обновления команд
	//pCmdUI->SetCheck(true);

}


void CMy1LBDoc::OnSettingsVisibillty()
{	
	if (!visibility) {
		visibility = TRUE;
	}
	else visibility = FALSE;
}


void CMy1LBDoc::OnUpdateSettingsVisibillty(CCmdUI* pCmdUI)
{
	// TODO: добавьте свой код обработчика ИП обновления команд
	if (visibility) {
		pCmdUI->SetCheck(true);
	} else pCmdUI->SetCheck(false);
}


void CMy1LBDoc::OnVisibility()
{
	// TODO: добавьте свой код обработчика команд
	if (!visibility) {
		visibility = TRUE;
	}
	else visibility = FALSE;
}
