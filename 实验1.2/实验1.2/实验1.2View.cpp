
// 实验1.2View.cpp : C实验12View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "实验1.2.h"
#endif

#include "实验1.2Doc.h"
#include "实验1.2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C实验12View

IMPLEMENT_DYNCREATE(C实验12View, CView)

BEGIN_MESSAGE_MAP(C实验12View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// C实验12View 构造/析构

C实验12View::C实验12View()
{
	// TODO: 在此处添加构造代码

}

C实验12View::~C实验12View()
{
}

BOOL C实验12View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C实验12View 绘制

void C实验12View::OnDraw(CDC* /*pDC*/)
{
	C实验12Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	// TODO: 在此处为本机数据添加绘制代码
}


// C实验12View 诊断

#ifdef _DEBUG
void C实验12View::AssertValid() const
{
	CView::AssertValid();
}

void C实验12View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C实验12Doc* C实验12View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C实验12Doc)));
	return (C实验12Doc*)m_pDocument;
}
#endif //_DEBUG


// C实验12View 消息处理程序


void C实验12View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	C实验12Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDoc->count += 1;
}


void C实验12View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	C实验12Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CClientDC dc(this);
	CString s;
	s.Format(_T("%d"), pDoc->count);
	dc.TextOutW(200, 200, s);
	CView::OnRButtonDown(nFlags, point);
}

