
// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "Origin.h"

#include "MainFrm.h"
#include "OriginView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

const int  iMaxUserToolbars = 10;
const UINT uiFirstUserToolBarId = AFX_IDW_CONTROLBAR_FIRST + 40;
const UINT uiLastUserToolBarId = uiFirstUserToolBarId + iMaxUserToolbars - 1;

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_COMMAND(ID_TEST, &CMainFrame::OnTest)
	ON_UPDATE_COMMAND_UI(ID_EDIT_COPY, &CMainFrame::OnUpdateEditCopy)
	ON_COMMAND(ID_TEST1_SHOW, &CMainFrame::OnTest1Show)
	ON_COMMAND(IDM_HELLO, OnHello)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	//m_bAutoMenuEnable = FALSE;
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO: Delete these three lines if you don't want the toolbar to be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	SetMenu(NULL);

	CMenu menu;
	menu.LoadMenu(IDR_MAINFRAME);
	SetMenu(&menu);
	menu.Detach();

	//auto format: Ctrl + K + F (selection), Ctrl + K + D (document)
	//GetMenu()->GetSubMenu(0)->CheckMenuItem(0, MF_BYPOSITION | MFS_CHECKED);
	GetMenu()->GetSubMenu(0)->CheckMenuItem(ID_FILE_NEW, MF_BYCOMMAND | MFS_CHECKED);
	//GetMenu()->GetSubMenu(0)->SetDefaultItem(1, TRUE);
	GetMenu()->GetSubMenu(0)->SetDefaultItem(ID_FILE_OPEN, FALSE); //overwritten by next line
	GetMenu()->GetSubMenu(0)->SetDefaultItem(5, TRUE);

	//CString str;
	//str.Format(L"x=%d, y=%d", GetSystemMetrics(SM_CXMENUCHECK), GetSystemMetrics(SM_CXMENUCHECK));
	//MessageBox(str);

	m_bitmap1.LoadBitmap(IDB_BITMAP1);
	m_bitmap2.LoadBitmap(IDB_BITMAP2);
	GetMenu()->GetSubMenu(2)->SetMenuItemBitmaps(0, MF_BYPOSITION, &m_bitmap1, &m_bitmap2);

	//GetMenu()->GetSubMenu(0)->EnableMenuItem(1, MF_BYPOSITION | MF_DISABLED | MF_GRAYED);

	CMenu menu2;
	menu2.CreateMenu();
	//GetMenu()->AppendMenu(MF_POPUP, (UINT)menu2.m_hMenu, L"Test2");
	GetMenu()->InsertMenu(2, MF_POPUP | MF_BYPOSITION, (UINT)menu2.m_hMenu, L"Test3");
	//menu2.AppendMenu(MF_STRING, 111, L"Hello");
	menu2.AppendMenu(MF_STRING, IDM_HELLO, L"Hello");
	menu2.AppendMenu(MF_STRING, 112, L"Bye");
	GetMenu()->GetSubMenu(0)->InsertMenu(ID_FILE_OPEN, MF_BYCOMMAND | MF_STRING, 113, L"VC");
	//GetMenu()->DeleteMenu(1, MF_BYPOSITION);
	GetMenu()->GetSubMenu(0)->DeleteMenu(1, MF_BYPOSITION);

	menu2.Detach();

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame message handlers



void CMainFrame::OnTest()
{
	// TODO: Add your command handler code here
	MessageBox(L"From MainFrame");
}


void CMainFrame::OnUpdateEditCopy(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	//if (ID_EDIT_COPY == pCmdUI->m_nID && 5 == pCmdUI->m_nIndex)
	pCmdUI->Enable();
}


void CMainFrame::OnTest1Show()
{
	// TODO: Add your command handler code here
	MessageBox(L"From MainFrame");
}

void CMainFrame::OnHello()
{
	MessageBox(L"Hello");
}

BOOL CMainFrame::OnCommand(WPARAM wParam, LPARAM lParam)
{
	// TODO: Add your specialized code here and/or call the base class
	int MenuCmdID = LOWORD(wParam);
	COriginView* pView = (COriginView*)GetActiveView();
	if (MenuCmdID >= IDM_PHONE1 && MenuCmdID < IDM_PHONE1 + pView->m_strArray.GetSize())
	{
		MessageBox(L"From CMainFrame::OnCommand()"); //This means CMainFrame captures OnCommand() first
		CClientDC dc(pView);
		dc.TextOutW(0, 0, pView->m_strArray.GetAt(MenuCmdID - IDM_PHONE1));
		return TRUE;
	}

	return CFrameWnd::OnCommand(wParam, lParam);
}
