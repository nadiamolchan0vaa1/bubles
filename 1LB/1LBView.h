
// 1LBView.h: интерфейс класса CMy1LBView
//

#pragma once
#include "1LBDoc.h"


class CMy1LBView : public CView
{
protected: // создать только из сериализации
	CMy1LBView() noexcept;
	DECLARE_DYNCREATE(CMy1LBView)

// Атрибуты
public:
	CMy1LBDoc* GetDocument() const;
	// CMy1LBDoc* pDoc;
// Операции
public:

// Переопределение
public:
	virtual void OnDraw(CDC* pDC);  // переопределено для отрисовки этого представления
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Реализация
public:
	virtual ~CMy1LBView();
	void fBrush(CPaintDC& dc);
	void OnPaint();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
//	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // версия отладки в 1LBView.cpp
inline CMy1LBDoc* CMy1LBView::GetDocument() const
   { return reinterpret_cast<CMy1LBDoc*>(m_pDocument); }
#endif

