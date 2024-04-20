
// 1LBView.cpp: реализация класса CMy1LBView
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "1LB.h"
#endif

#include "1LBDoc.h"
#include "1LBView.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace std;

// CMy1LBView

IMPLEMENT_DYNCREATE(CMy1LBView, CView)

BEGIN_MESSAGE_MAP(CMy1LBView, CView)
	// Стандартные команды печати
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_TIMER()
//	ON_WM_CREATE()
ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// Создание или уничтожение CMy1LBView

CMy1LBView::CMy1LBView() noexcept
{
	// TODO: добавьте код создания

}

CMy1LBView::~CMy1LBView()
{

}

BOOL CMy1LBView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Рисование CMy1LBView

void CMy1LBView::OnDraw(CDC* pDC)
{
	CMy1LBDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	//pDoc->m_circ.Draw(pDC);
	if (pDoc->visibility) {
		for (int i = 0; i < pDoc->bubbles.size(); i++) {
			pDoc->bubbles[i].Draw(pDC);
		}
	}

	/*CPen pen;
	pen.CreatePen(PS_DASHDOT, pDoc->m_Thickness, pDoc->m_Color);
	CPen* oldPen = pDC->SelectObject(&pen);
	pDC->LineTo(200, 200);

	pDC->SelectObject(oldPen);*/

	//SetDCPenColor(pDC->GetSafeHdc(), 0x00FF0000);
	//pDC->Ellipse(250, 100, 175, 200);
	// TODO: добавьте здесь код отрисовки для собственных данных
	//Invalidate(TRUE); принудительная перерисовка вида или окна
	//если хотим fps, делаем таймер на окно(живет всегда в окне их несколько может быть)
	//
	/*CRect(rect);
	GetClientRect(&rect);

	pDC->MoveTo(0, rect.Height()/2);
	pDC->LineTo(rect.Width(), rect.Height() / 2);

	pDC->MoveTo(0, rect.Height() / 2);

	for (double i = 0; i < rect.Width(); i+=0.1)
	{
		pDC->LineTo(i * (rect.Width() / 3.14) / 2, -sin(i) * rect.Height()/2 + rect.Height()/2);
	}*/
}


// Печать CMy1LBView

BOOL CMy1LBView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// подготовка по умолчанию
	return DoPreparePrinting(pInfo);
}

void CMy1LBView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте дополнительную инициализацию перед печатью
}

void CMy1LBView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте очистку после печати
}


// Диагностика CMy1LBView

#ifdef _DEBUG
void CMy1LBView::AssertValid() const
{
	CView::AssertValid();
}

void CMy1LBView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy1LBDoc* CMy1LBView::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy1LBDoc)));
	return (CMy1LBDoc*)m_pDocument;
}
#endif //_DEBUG


// Обработчики сообщений CMy1LBView

//закрытие окна
void CMy1LBView::OnInitialUpdate() 
{
	CView::OnInitialUpdate();
	//создание таймера
	SetTimer(0, 10, NULL);

	CMy1LBDoc* pDoc = GetDocument();

	srand(time(NULL));
	int amount = 1 + rand() % 8;
	//amount = 2;
	pDoc->bubbles.resize(amount);

	CRect rect;
	GetClientRect(&rect);

	for (int i = 0; i < pDoc->bubbles.size(); i++) {
		while (true)
		{
			pDoc->bubbles[i].Сreate(rect.Height(), rect.Width());
			bool check = true;
			for (int j = 0; j < i; j++) {
				double distance = sqrt(pow(pDoc->bubbles[i].m_x - pDoc->bubbles[j].m_x, 2) + pow(pDoc->bubbles[i].m_y - pDoc->bubbles[j].m_y, 2));
				if (distance <= pDoc->bubbles[i].m_r + pDoc->bubbles[j].m_r){
					check = false;
					break;
				}
			}
			if (check)
				break;
		}
	}
	// TODO: добавьте специализированный код или вызов базового класса
}


void CMy1LBView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного

	CMy1LBDoc* pDoc = GetDocument();

	CRect rect;
	GetClientRect(&rect);
	if (pDoc->visibility) {
		for (int i = 0; i < pDoc->bubbles.size(); i++) {
			pDoc->bubbles[i].Traffic(rect.Height(), rect.Width());
			for (int j = i + 1; j < pDoc->bubbles.size(); j++) {
				pDoc->bubbles[i].Bump(pDoc->bubbles[j]);
			}
		}
	}
	// перерисовка вида
	Invalidate();
	//обработчик таймера
	CView::OnTimer(nIDEvent);

}


//int CMy1LBView::OnCreate(LPCREATESTRUCT lpCreateStruct)
//{
//	lpCreateStruct->style |= TVS_HASLINES | TVS_HASBUTTONS
//		| TVS_LINESATROOT | TVS_SHOWSELALWAYS;// | TVS_CHECKBOXES;
//
//	if (CView::OnCreate(lpCreateStruct) == -1)
//		return -1;
//
//	// TODO:  Добавьте специализированный код создания
//
//	return 0;
//}


void CMy1LBView::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	CMenu MainMenu;
	MainMenu.LoadMenuW(IDR_MAINFRAME);
	CMenu* SubMenu = MainMenu.GetSubMenu(3);

	ClientToScreen(&point);

	SubMenu->TrackPopupMenu(TPM_LEFTALIGN, point.x, point.y, this);

	CView::OnRButtonUp(nFlags, point);
}