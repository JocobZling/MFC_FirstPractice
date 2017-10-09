
// HelloWorldView.h : CHelloWorldView 类的接口
//

#pragma once


class CHelloWorldView : public CView
{
protected: // 仅从序列化创建
	CHelloWorldView();
	DECLARE_DYNCREATE(CHelloWorldView)

// 特性
public:
	CHelloWorldDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CHelloWorldView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected: 
	afx_msg LRESULT OnHide(WPARAM wParam, LPARAM lParam);

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTestmessageSendmessage();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // HelloWorldView.cpp 中的调试版本
inline CHelloWorldDoc* CHelloWorldView::GetDocument() const
   { return reinterpret_cast<CHelloWorldDoc*>(m_pDocument); }
#endif

