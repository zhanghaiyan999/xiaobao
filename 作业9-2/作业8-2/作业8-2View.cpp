
// 作业8-2View.cpp : C作业82View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "作业8-2.h"
#endif

#include "作业8-2Doc.h"
#include "作业8-2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C作业82View

IMPLEMENT_DYNCREATE(C作业82View, CView)

BEGIN_MESSAGE_MAP(C作业82View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// C作业82View 构造/析构

C作业82View::C作业82View()
{
	// TODO: 在此处添加构造代码


}

C作业82View::~C作业82View()
{
}

BOOL C作业82View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C作业82View 绘制

void C作业82View::OnDraw(CDC* pDC)
{
	C作业82Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
for (int i = 0; i <pDoc->ca.GetSize(); i++)
		pDC->Ellipse(pDoc->ca.GetAt(i));
	// TODO: 在此处为本机数据添加绘制代码
}


// C作业82View 诊断

#ifdef _DEBUG
void C作业82View::AssertValid() const
{
	CView::AssertValid();
}

void C作业82View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C作业82Doc* C作业82View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C作业82Doc)));
	return (C作业82Doc*)m_pDocument;
}
#endif //_DEBUG


// C作业82View 消息处理程序


void C作业82View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	x1 = point.x;
	y1 = point.y;
	flag = 1;
	CView::OnLButtonDown(nFlags, point);
}


void C作业82View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	C作业82Doc* pDoc = GetDocument();
	CClientDC dc(this);
	x2 = point.x;
	y2 = point.y;
	A.left = x1;
	A.top = y1;
	A.right = x2;
	A.bottom = y2;
	Invalidate();
	flag = 0;
	pDoc->ca.Add(A);
	Invalidate();
	CView::OnLButtonUp(nFlags, point);
}


void C作业82View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (flag == 1)
	{
		CClientDC dc(this);
		x2 = point.x;
		y2 = point.y;
		A.left = x1;
		A.top = y1;
		A.right = x2;
		A.bottom = y2;
		dc.Ellipse(A);
		Invalidate();
	}
	CView::OnMouseMove(nFlags, point);
}
