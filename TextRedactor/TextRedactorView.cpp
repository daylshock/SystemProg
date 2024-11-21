
// TextRedactorView.cpp: реализация класса CTextRedactorView
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "TextRedactor.h"
#endif

#include "TextRedactorDoc.h"
#include "CntrItem.h"
#include "resource.h"
#include "TextRedactorView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTextRedactorView

IMPLEMENT_DYNCREATE(CTextRedactorView, CRichEditView)

BEGIN_MESSAGE_MAP(CTextRedactorView, CRichEditView)
	ON_WM_DESTROY()
	// Стандартные команды печати
	ON_COMMAND(ID_FILE_PRINT, &CRichEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRichEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CRichEditView::OnFilePrintPreview)
END_MESSAGE_MAP()

// Создание или уничтожение CTextRedactorView

CTextRedactorView::CTextRedactorView() noexcept
{
	// TODO: добавьте код создания

}

CTextRedactorView::~CTextRedactorView()
{
}

BOOL CTextRedactorView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CRichEditView::PreCreateWindow(cs);
}

void CTextRedactorView::OnInitialUpdate()
{
	CRichEditView::OnInitialUpdate();


	// Задайте границы печати (720 твип = 1/2 дюйма)
	SetMargins(CRect(720, 720, 720, 720));
}


// Печать CTextRedactorView

BOOL CTextRedactorView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// подготовка по умолчанию
	return DoPreparePrinting(pInfo);
}


void CTextRedactorView::OnDestroy()
{
	// Деактивируйте элемент при удалении; это важно
	// в случае использования представления разделителя
   COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
   if (pActiveItem != nullptr && pActiveItem->GetActiveView() == this)
   {
      pActiveItem->Deactivate();
      ASSERT(GetDocument()->GetInPlaceActiveItem(this) == nullptr);
   }
   CRichEditView::OnDestroy();
}



// Диагностика CTextRedactorView

#ifdef _DEBUG
void CTextRedactorView::AssertValid() const
{
	CRichEditView::AssertValid();
}

void CTextRedactorView::Dump(CDumpContext& dc) const
{
	CRichEditView::Dump(dc);
}

CTextRedactorDoc* CTextRedactorView::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTextRedactorDoc)));
	return (CTextRedactorDoc*)m_pDocument;
}
#endif //_DEBUG


// Обработчики сообщений CTextRedactorView
