
// HelloWorldView.cpp : CHelloWorldView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)

	ON_MESSAGE(WM_HIDE, OnHide)
	ON_COMMAND(ID_TESTMESSAGE_SENDMESSAGE, &CHelloWorldView::OnTestmessageSendmessage)
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CHelloWorldView ����/����

CHelloWorldView::CHelloWorldView()
{
	// TODO: �ڴ˴���ӹ������

}

CHelloWorldView::~CHelloWorldView()
{
}

BOOL CHelloWorldView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CHelloWorldView ����

void CHelloWorldView::OnDraw(CDC* pDC)
{
	CHelloWorldDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	//-TҲ��
	pDC->TextOut(0,0,L"Hello world!");
}
LRESULT CHelloWorldView::OnHide(WPARAM wParam,LPARAM lParam)
{
	MessageBox(L"Hide");
	return 0;
}

// CHelloWorldView ��ӡ

BOOL CHelloWorldView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CHelloWorldView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CHelloWorldView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CHelloWorldView ���

#ifdef _DEBUG
void CHelloWorldView::AssertValid() const
{
	CView::AssertValid();
}

void CHelloWorldView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CHelloWorldDoc* CHelloWorldView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHelloWorldDoc)));
	return (CHelloWorldDoc*)m_pDocument;
}
#endif //_DEBUG


// CHelloWorldView ��Ϣ�������


void CHelloWorldView::OnTestmessageSendmessage()
{
	// TODO: Add your command handler code here
	PostMessage(WM_HIDE,0,0);
}


void CHelloWorldView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CString str;
	CStatusBar* pStatus;//���ڻ�ȡ��ǰӦ�ó������

	str.Format(L"X=%d Y=%d",point.x,point.y);
	pStatus=(CStatusBar*)(AfxGetApp()->
		m_pMainWnd->GetDescendantWindow(
		AFX_IDW_STATUS_BAR));
	pStatus->SetPaneText(1,str);//���ڻ�ȡ�����ڶ���

	CView::OnMouseMove(nFlags, point);
}
