
// TextRedactorDoc.cpp: реализация класса CTextRedactorDoc 
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

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CTextRedactorDoc

IMPLEMENT_DYNCREATE(CTextRedactorDoc, CRichEditDoc)

BEGIN_MESSAGE_MAP(CTextRedactorDoc, CRichEditDoc)
	// Включите реализацию контейнера OLE
	ON_UPDATE_COMMAND_UI(ID_OLE_EDIT_LINKS, &CRichEditDoc::OnUpdateEditLinksMenu)
	ON_UPDATE_COMMAND_UI(ID_OLE_VERB_POPUP, &CTextRedactorDoc::OnUpdateObjectVerbPopup)
	ON_COMMAND(ID_OLE_EDIT_LINKS, &CRichEditDoc::OnEditLinks)
	ON_UPDATE_COMMAND_UI_RANGE(ID_OLE_VERB_FIRST, ID_OLE_VERB_LAST, &CRichEditDoc::OnUpdateObjectVerbMenu)
END_MESSAGE_MAP()


// Создание или уничтожение CTextRedactorDoc

CTextRedactorDoc::CTextRedactorDoc() noexcept
{
	// Используйте объединенные файлы OLE
	EnableCompoundFile();

	// TODO: добавьте код для одноразового вызова конструктора

}

CTextRedactorDoc::~CTextRedactorDoc()
{
}

BOOL CTextRedactorDoc::OnNewDocument()
{
	if (!CRichEditDoc::OnNewDocument())
		return FALSE;

	// TODO: добавьте код повторной инициализации
	// (Документы SDI будут повторно использовать этот документ)

	return TRUE;
}

CRichEditCntrItem* CTextRedactorDoc::CreateClientItem(REOBJECT* preo) const
{
	return new CTextRedactorCntrItem(preo, const_cast<CTextRedactorDoc*>(this));
}




// Сериализация CTextRedactorDoc

void CTextRedactorDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: добавьте код сохранения
	}
	else
	{
		// TODO: добавьте код загрузки
	}

	// Вызов базового класса CRichEditDoc включает сериализацию
	//  объектов COleClientItem документа контейнера.
	// TODO: задайте CRichEditDoc::m_bRTF = FALSE в случае сериализации как текста
	CRichEditDoc::Serialize(ar);
}

#ifdef SHARED_HANDLERS

// Поддержка для эскизов
void CTextRedactorDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void CTextRedactorDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Задание содержимого поиска из данных документа.
	// Части содержимого должны разделяться точкой с запятой ";"

	// Например:  strSearchContent = _T("точка;прямоугольник;круг;объект ole;");
	SetSearchContent(strSearchContent);
}

void CTextRedactorDoc::SetSearchContent(const CString& value)
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

// Диагностика CTextRedactorDoc

#ifdef _DEBUG
void CTextRedactorDoc::AssertValid() const
{
	CRichEditDoc::AssertValid();
}

void CTextRedactorDoc::Dump(CDumpContext& dc) const
{
	CRichEditDoc::Dump(dc);
}
#endif //_DEBUG


// Команды CTextRedactorDoc
