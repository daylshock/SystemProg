
// CntrItem.h: интерфейс класса CTextRedactorCntrItem
//

#pragma once

class CTextRedactorDoc;
class CTextRedactorView;

class CTextRedactorCntrItem : public CRichEditCntrItem
{
	DECLARE_SERIAL(CTextRedactorCntrItem)

// Конструкторы
public:
	CTextRedactorCntrItem(REOBJECT* preo = nullptr, CTextRedactorDoc* pContainer = nullptr);
		// Примечание. pContainer может иметь значение NULL для разрешения IMPLEMENT_SERIALIZE
		//  IMPLEMENT_SERIALIZE требует наличия у класса конструктора с
		//  нулевым аргументами.  Обычно элементы OLE создаются с
		//  указателями на документ, не равными NULL

// Атрибуты
public:
	CTextRedactorDoc* GetDocument()
		{ return reinterpret_cast<CTextRedactorDoc*>(CRichEditCntrItem::GetDocument()); }
	CTextRedactorView* GetActiveView()
		{ return reinterpret_cast<CTextRedactorView*>(CRichEditCntrItem::GetActiveView()); }

// Реализация
public:
	~CTextRedactorCntrItem();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

