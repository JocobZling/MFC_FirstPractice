
// MainFrm.cpp : CMainFrame 类的实现
//

#include "stdafx.h"
#include "HelloWorld.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
//	ON_WM_UNICHAR()
	ON_WM_TIMER()
	ON_WM_PAINT()
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // 状态行指示器
	ID_SEPARATOR,           //Mouse pointOR
	ID_INDICATOR_TIME,		//time
	ID_INDICATOR_PROGRESS,  //time后的小窗口
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,

};

// CMainFrame 构造/析构

CMainFrame::CMainFrame()
{
	// TODO: 在此添加成员初始化代码
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
		TRACE0("未能创建工具栏\n");
		return -1;      // 未能创建
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("未能创建状态栏\n");
		return -1;      // 未能创建
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO: 如果不需要可停靠工具栏，则删除这三行
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);
	
	SetTimer(1,1000,NULL);
	CTime time =CTime ::GetCurrentTime();
	CString str =time.Format(L"%H:%M:%S");
	CClientDC dc(this);
	CSize sz =dc.GetTextExtent(str);//获得字符的宽高度信息
	m_wndStatusBar.SetPaneInfo(2,ID_INDICATOR_TIME,SBPS_POPOUT,sz.cx);
	m_wndStatusBar.SetPaneText(2,str);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return TRUE;
}

// CMainFrame 诊断

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


// CMainFrame 消息处理程序


//void CMainFrame::OnUniChar(UINT Char, UINT nRepCnt, UINT nFlags)
//{
//	// TODO: Add your message handler code here and/or call default
//
//	CFrameWnd::OnUniChar(Char, nRepCnt, nFlags);
//}


void CMainFrame::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	CTime time =CTime ::GetCurrentTime();
	CString str = time.Format(L"%H:%M:%S");
	m_wndStatusBar.SetPaneText(2,str);

	m_ctrlProgress.StepIt();

	CFrameWnd::OnTimer(nIDEvent);
}


void CMainFrame::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here
	// Do not call CFrameWnd::OnPaint() for painting messages
	
	CRect rect;
	m_wndStatusBar.GetItemRect(3,&rect);
	if(m_ctrlProgress.m_hWnd)
		m_ctrlProgress.SetWindowPos(NULL,
		rect.left,rect.top,
		rect.Width(),rect.Height(),
		SWP_NOZORDER);
	else
		m_ctrlProgress.Create(WS_CHILD	|	WS_VISIBLE,rect,&m_wndStatusBar,111);
}
