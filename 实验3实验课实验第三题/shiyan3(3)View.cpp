
// shiyan3(3)View.cpp: Cshiyan33View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "shiyan3(3).h"
#endif

#include "shiyan3(3)Doc.h"
#include "shiyan3(3)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cshiyan33View

IMPLEMENT_DYNCREATE(Cshiyan33View, CView)

BEGIN_MESSAGE_MAP(Cshiyan33View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// Cshiyan33View 构造/析构

Cshiyan33View::Cshiyan33View() noexcept
{
	// TODO: 在此处添加构造代码

}

Cshiyan33View::~Cshiyan33View()
{
}

BOOL Cshiyan33View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cshiyan33View 绘图

void Cshiyan33View::OnDraw(CDC* pDC)
{
	Cshiyan33Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CRect cr(500, 500, 600, 600);
	CRect cr1(300, 300, 400, 400);
	CRect cr2(600, 600, 700, 700);
	pDC->Rectangle(&cr);             //在ondraw里面画三个矩形
	pDC->Rectangle(&cr1);
	pDC->Rectangle(&cr2);
	int a = rand() % 50 + 5;
	int b = rand() % 100 + 20;
	int c = 0;


}

void Cshiyan33View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Cshiyan33View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Cshiyan33View 诊断

#ifdef _DEBUG
void Cshiyan33View::AssertValid() const
{
	CView::AssertValid();
}

void Cshiyan33View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cshiyan33Doc* Cshiyan33View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cshiyan33Doc)));
	return (Cshiyan33Doc*)m_pDocument;
}
#endif //_DEBUG


// Cshiyan33View 消息处理程序


void Cshiyan33View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	/*Cshiyan33Doc* pDoc = GetDocument();
	int r = 10;
	int r1 = 20;
	CRect rect(point.x - r, point.y - r1, point.x + r, point.y + r1);
	pDoc->ca.Add(rect);
	this->Invalidate();
	CView::OnLButtonDown(nFlags, point);*/
	Cshiyan33Doc* pDoc = GetDocument();
	CClientDC dc(this);
	CString s1,s2,s3,s4;
	s1.Format(_T("%d"), pDoc->a);
	s2.Format(_T("%d"),pDoc->b);
	s3.Format(_T("a+b=%d"), pDoc->a+pDoc->b);
	s4.Format(_T("点击无效"));
	if (point.x > 500 && point.x < 600 && point.y>500 && point.y < 600)
		dc.TextOutW(point.x, point.y, s1);
	else if(point.x > 300 && point.x < 400 && point.y>300 && point.y < 400)
		dc.TextOutW(point.x, point.y, s2);
	else if(point.x > 600 && point.x < 700 && point.y>600 && point.y < 700)
		dc.TextOutW(point.x, point.y, s3);
	else {		
		dc.TextOutW(point.x, point.y, s4);

	}
}
