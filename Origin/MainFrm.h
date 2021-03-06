
// MainFrm.h : interface of the CMainFrame class
//

#pragma once

class CMainFrame : public CFrameWnd
{
	
protected: // create from serialization only
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CToolBar          m_wndToolBar;
	CStatusBar        m_wndStatusBar;

// Generated message map functions
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnHello(); //manually added
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnTest();
	CBitmap m_bitmap1;
	CBitmap m_bitmap2;
	afx_msg void OnUpdateEditCopy(CCmdUI *pCmdUI);
	afx_msg void OnTest1Show();
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
};


