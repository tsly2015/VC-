
// OriginView.cpp : implementation of the COriginView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Origin.h"
#endif

#include "OriginDoc.h"
#include "OriginView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// COriginView

IMPLEMENT_DYNCREATE(COriginView, CView)

BEGIN_MESSAGE_MAP(COriginView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_TEST, &COriginView::OnTest)
//	ON_COMMAND(ID_TEST1_SHOW, &COriginView::OnTest1Show)
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_TEST1_SHOW, &COriginView::OnTest1Show)
END_MESSAGE_MAP()

// COriginView construction/destruction

COriginView::COriginView()
{
	// TODO: add construction code here

}

COriginView::~COriginView()
{
}

BOOL COriginView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// COriginView drawing

void COriginView::OnDraw(CDC* /*pDC*/)
{
	COriginDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// COriginView printing

BOOL COriginView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void COriginView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void COriginView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// COriginView diagnostics

#ifdef _DEBUG
void COriginView::AssertValid() const
{
	CView::AssertValid();
}

void COriginView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

COriginDoc* COriginView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COriginDoc)));
	return (COriginDoc*)m_pDocument;
}
#endif //_DEBUG


// COriginView message handlers


void COriginView::OnTest()
{
	// TODO: Add your command handler code here
	//CCmdTarget -> CWnd -> CView, CMainFrame
	//CCmdTarget -> CDocument, CWinApp
	MessageBox(L"From View"); //View, Doc, MainFrame, App
}


//void COriginView::OnTest1Show()
//{
//	// TODO: Add your command handler code here
//	MessageBox(L"From View");
//}


void COriginView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CMenu menu;
	menu.LoadMenu(IDR_MENU1);
	CMenu* pPopup = menu.GetSubMenu(0);

	ClientToScreen(&point);
	//pPopup->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this); //only View, no MainFrame
	pPopup->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, GetParent()); //if no View, then MainFrame

	CView::OnRButtonDown(nFlags, point);
}


void COriginView::OnTest1Show()
{
	// TODO: Add your command handler code here
	MessageBox(L"From View");
}
