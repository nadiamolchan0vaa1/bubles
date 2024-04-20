#pragma once
#include "afxcview.h"
//#include "1LBDoc.h"
class CMy1LBDoc; //форвард диклорейшн

// Просмотр CMyTreeView

class CMyTreeView : public CTreeView
{
	DECLARE_DYNCREATE(CMyTreeView)

protected:
	CMyTreeView();           // защищенный конструктор, используемый при динамическом создании
	virtual ~CMyTreeView();

public:
	CMy1LBDoc* m_pDoc;
	HTREEITEM m_hColor, m_hIhick, m_hColor1, m_hColor2, m_hColor3, m_hThickness, m_hThickness1, m_hThickness2, m_hThickness3, m_hColor4;



	void FillTree();




#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
};


