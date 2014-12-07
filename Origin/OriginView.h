
// OriginView.h : interface of the COriginView class
//

#pragma once

#include "OriginDoc.h"

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
//	afx_msg void OnTest1Show();
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnTest1Show();
private:
	int m_nIndex;
	CMenu m_menu;
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
private:
	CString m_strLine;
public:
	CStringArray m_strArray;
	afx_msg void OnPhone1();
	afx_msg void OnPhone2();
	afx_msg void OnPhone3();
	afx_msg void OnPhone4();
};

#ifndef _DEBUG  // debug version in OriginView.cpp
inline COriginDoc* COriginView::GetDocument() const
   { return reinterpret_cast<COriginDoc*>(m_pDocument); }
#endif

