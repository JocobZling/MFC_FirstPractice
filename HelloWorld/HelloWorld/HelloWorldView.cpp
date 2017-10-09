
// HelloWorldView.cpp : CHelloWorldView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "HelloWorld.h"
#endif

#include "HelloWorldDoc.h"
#include "HelloWorldView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CHelloWorldView

IMPLEMENT_DYNCREATE(CHelloWorldView, CView)

BEGIN_MESSAGE_MAP(CHelloWorldView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)

	ON_MESSAGE(WM_HIDE, OnHide)
	ON_COMMAND(ID_TESTMESSAGE_SENDMESSAGE, &CHelloWorldView::OnTestmessageSendmessage)
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CHelloWorldView 构造/析构

CHelloWorldView::CHelloWorldView()
{
	// TODO: 在此处添加构造代码

}

CHelloWorldView::~CHelloWorldView()
{
}

BOOL CHelloWorldView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CHelloWorldView 绘制

void CHelloWorldView::OnDraw(CDC* pDC)
{
	CHelloWorldDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	//-T也可
	pDC->TextOut(0,0,L"Hello world!");
}
LRESULT CHelloWorldView::OnHide(WPARAM wParam,LPARAM lParam)
{
	MessageBox(L"Hide");
	return 0;
}

// CHelloWorldView 打印

BOOL CHelloWorldView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CHelloWorldView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CHelloWorldView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CHelloWorldView 诊断

#ifdef _DEBUG
void CHelloWorldView::AssertValid() const
{
	CView::AssertValid();
}

void CHelloWorldView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CHelloWorldDoc* CHelloWorldView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHelloWorldDoc)));
	return (CHelloWorldDoc*)m_pDocument;
}
#endif //_DEBUG


// CHelloWorldView 消息处理程序


void CHelloWorldView::OnTestmessageSendmessage()
{
	// TODO: Add your command handler code here
	PostMessage(WM_HIDE,0,0);
}


void CHelloWorldView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CString str;
	CStatusBar* pStatus;//用于获取当前应用程序对象

	str.Format(L"X=%d Y=%d",point.x,point.y);
	pStatus=(CStatusBar*)(AfxGetApp()->
		m_pMainWnd->GetDescendantWindow(
		AFX_IDW_STATUS_BAR));
	pStatus->SetPaneText(1,str);//用于获取主窗口对象

	CView::OnMouseMove(nFlags, point);
}
