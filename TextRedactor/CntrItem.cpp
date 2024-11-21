
// CntrItem.cpp: реализация класса CTextRedactorCntrItem
//

#include "pch.h"
#include "framework.h"
#include "TextRedactor.h"

#include "TextRedactorDoc.h"
#include "TextRedactorView.h"
#include "CntrItem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Реализация CTextRedactorCntrItem

IMPLEMENT_SERIAL(CTextRedactorCntrItem, CRichEditCntrItem, 0)

CTextRedactorCntrItem::CTextRedactorCntrItem(REOBJECT* preo, CTextRedactorDoc* pContainer)
	: CRichEditCntrItem(preo, pContainer)
{
	// TODO: добавьте код для одноразового вызова конструктора
}

CTextRedactorCntrItem::~CTextRedactorCntrItem()
{
	// TODO: добавьте код очистки
}


// Диагностика CTextRedactorCntrItem

#ifdef _DEBUG
void CTextRedactorCntrItem::AssertValid() const
{
	CRichEditCntrItem::AssertValid();
}

void CTextRedactorCntrItem::Dump(CDumpContext& dc) const
{
	CRichEditCntrItem::Dump(dc);
}
#endif

