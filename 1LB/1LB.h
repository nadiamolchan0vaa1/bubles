
// 1LB.h: основной файл заголовка для приложения 1LB
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CMy1LBApp:
// Сведения о реализации этого класса: 1LB.cpp
//

class CMy1LBApp : public CWinApp
{
public:
	CMy1LBApp() noexcept;


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy1LBApp theApp;
