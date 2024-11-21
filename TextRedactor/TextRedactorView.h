
// TextRedactorView.h: интерфейс класса CTextRedactorView
//

#pragma once

class CTextRedactorCntrItem;

class CTextRedactorView : public CRichEditView
{
protected: // создать только из сериализации
	CTextRedactorView() noexcept;
	DECLARE_DYNCREATE(CTextRedactorView)

// Атрибуты
public:
	CTextRedactorDoc* GetDocument() const;

// Операции
public:

// Переопределение
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // вызывается в первый раз после конструктора
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);

// Реализация
public:
	virtual ~CTextRedactorView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	afx_msg void OnDestroy();
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // версия отладки в TextRedactorView.cpp
inline CTextRedactorDoc* CTextRedactorView::GetDocument() const
   { return reinterpret_cast<CTextRedactorDoc*>(m_pDocument); }
#endif

