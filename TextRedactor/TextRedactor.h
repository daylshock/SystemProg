
// TextRedactor.h: основной файл заголовка для приложения TextRedactor
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CTextRedactorApp:
// Сведения о реализации этого класса: TextRedactor.cpp
//

class CTextRedactorApp : public CWinApp
{
public:
	CTextRedactorApp() noexcept;


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CTextRedactorApp theApp;
