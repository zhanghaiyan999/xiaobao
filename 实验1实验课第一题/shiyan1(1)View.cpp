
// shiyan1(1)View.cpp: Cshiyan11View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "shiyan1(1).h"
#endif

#include "shiyan1(1)Doc.h"
#include "shiyan1(1)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cshiyan11View

IMPLEMENT_DYNCREATE(Cshiyan11View, CView)

BEGIN_MESSAGE_MAP(Cshiyan11View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// Cshiyan11View 构造/析构

Cshiyan11View::Cshiyan11View() noexcept
{
	// TODO: 在此处添加构造代码

}

Cshiyan11View::~Cshiyan11View()
{
}

BOOL Cshiyan11View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cshiyan11View 绘图

void Cshiyan11View::OnDraw(CDC* pDC)
{
	Cshiyan11Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}

void Cshiyan11View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Cshiyan11View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Cshiyan11View 诊断

#ifdef _DEBUG
void Cshiyan11View::AssertValid() const
{
	CView::AssertValid();
}

void Cshiyan11View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cshiyan11Doc* Cshiyan11View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cshiyan11Doc)));
	return (Cshiyan11Doc*)m_pDocument;
}
#endif //_DEBUG


// Cshiyan11View 消息处理程序


void Cshiyan11View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CDC* pDC;
	Cshiyan11Doc* pDoc = GetDocument();
	CClientDC dc(this);
	dc.TextOutW(200, 200, pDoc->s);
	CView::OnLButtonDown(nFlags, point);
}
