
// OriginView.h : interface of the COriginView class
//

#pragma once


class COriginView : public CView
{
protected: // create from serialization only
	COriginView();
	DECLARE_DYNCREATE(COriginView)

// Attributes
public:
	COriginDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~COriginView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTest();
};

#ifndef _DEBUG  // debug version in OriginView.cpp
inline COriginDoc* COriginView::GetDocument() const
   { return reinterpret_cast<COriginDoc*>(m_pDocument); }
#endif

