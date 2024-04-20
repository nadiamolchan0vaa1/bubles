
// 1LBDoc.h: интерфейс класса CMy1LBDoc 
//

#pragma once
#include <vector>
#include "CMyTreeView.h"
#include "ThicknessDlg.h"
#include "ColorDlg.h"


class CMyCircle
{
public:

	int m_x, m_y, m_r, deltaX, deltaY;
	CMyCircle();
	//CMyCircle(int x, int y, int r);
	int height1;
	int width1;
	int r, g, b;
	int thickness;
	COLORREF myColor;

	//рисовашка
	void Draw(CDC *pDC);

	void Сreate(int height, int width);
	void Traffic(int, int);

	void SetColor(int, int, int);
	void SetThickness(int);

	void Bump(CMyCircle&);
	
};


class CMy1LBDoc : public CDocument
{
protected: // создать только из сериализации
	CMy1LBDoc() noexcept;
	DECLARE_DYNCREATE(CMy1LBDoc)

// Атрибуты
public:
	/*int x, y, r;
	bool m_bDraw = true;*/
	int m_Iversion;

	ColorDlg m_ColorDlg;

	std :: vector <CMyCircle> bubbles;
	int n_bubbles;

	CMyTreeView* m_pTreeView;

	bool m_bRed, m_bGreen, m_bBlue;
	COLORREF m_Color = RGB(255, 0, 0);
	int m_Thickness = 1;
	CMy1LBDoc* m_pDoc;
	bool visibility;
	

// Операции
public:

// Переопределение
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Реализация
public:
	virtual ~CMy1LBDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Вспомогательная функция, задающая содержимое поиска для обработчика поиска
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void OnSettingsColor();
	afx_msg void OnSettingsThickness();
	afx_msg void OnUpdateSettingsColor(CCmdUI* pCmdUI);
	afx_msg void OnSettingsVisibillty();
	afx_msg void OnUpdateSettingsVisibillty(CCmdUI* pCmdUI);
	afx_msg void OnVisibility();
};
