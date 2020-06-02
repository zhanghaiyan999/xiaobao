
// shiyanclass(1)View.cpp: Cshiyanclass1View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "shiyanclass(1).h"
#endif

#include "shiyanclass(1)Doc.h"
#include "shiyanclass(1)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cshiyanclass1View

IMPLEMENT_DYNCREATE(Cshiyanclass1View, CView)

BEGIN_MESSAGE_MAP(Cshiyanclass1View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// Cshiyanclass1View 构造/析构

Cshiyanclass1View::Cshiyanclass1View() noexcept
{
	// TODO: 在此处添加构造代码
}

Cshiyanclass1View::~Cshiyanclass1View()
{
}

BOOL Cshiyanclass1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cshiyanclass1View 绘图

void Cshiyanclass1View::OnDraw(CDC* pDC)//pDC设备环境类
{
	Cshiyanclass1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: 在此处为本机数据添加绘制代码
	for (int i = 0; i < pDoc->ca.GetSize(); i++)
		pDC->Ellipse(pDoc->ca.GetAt(i));//在onDraw里面画圆

}

void Cshiyanclass1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Cshiyanclass1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Cshiyanclass1View 诊断

#ifdef _DEBUG
void Cshiyanclass1View::AssertValid() const
{
	CView::AssertValid();
}

void Cshiyanclass1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cshiyanclass1Doc* Cshiyanclass1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cshiyanclass1Doc)));
	return (Cshiyanclass1Doc*)m_pDocument;
}
#endif //_DEBUG


// Cshiyanclass1View 消息处理程序


void Cshiyanclass1View::OnLButtonDown(UINT nFlags, CPoint point)//point 客户区中心点的的位置
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	Cshiyanclass1Doc* pDoc = GetDocument();
	CRect cr;//客户区
	this->GetClientRect(&cr);//获得客户区的矩形
	CClientDC dc(this);//构造客户区DC
	int r = (cr.top - cr.bottom) / 2;//获取客户区最短的边作为矩形
	CRect cr1(point.x-r,point.y-r,point.x+r,point.y+r);
	pDoc->ca.Add(cr1);
	this->Invalidate();
	
	CView::OnLButtonDown(nFlags, point);
}
