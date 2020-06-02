
// MFCApplication7(1)View.cpp: CMFCApplication71View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication7(1).h"
#endif

#include "MFCApplication7(1)Doc.h"
#include "MFCApplication7(1)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication71View

IMPLEMENT_DYNCREATE(CMFCApplication71View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication71View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMFCApplication71View 构造/析构

CMFCApplication71View::CMFCApplication71View() noexcept
{
	// TODO: 在此处添加构造代码
	point1.x = 50;
	point1.y = 50;
	m = false;
}

CMFCApplication71View::~CMFCApplication71View()
{
}

BOOL CMFCApplication71View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication71View 绘图

void CMFCApplication71View::OnDraw(CDC* pDC)
{
	CMFCApplication71Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 
	CClientDC dc(this);
	
	int r1 = 30;
	int r2 = 40;


	dc.Rectangle(point1.x -r1,point1.y-r1, point1.x +r2, point1.y + r2);//客户区画矩形

	//dc.Rectangle(pDoc->m_tagRec);//客户区画矩形
}

void CMFCApplication71View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCApplication71View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCApplication71View 诊断

#ifdef _DEBUG
void CMFCApplication71View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication71View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication71Doc* CMFCApplication71View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication71Doc)));
	return (CMFCApplication71Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication71View 消息处理程序


void CMFCApplication71View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	Invalidate();
	

	
	
	CView::OnLButtonDown(nFlags, point);
}


void CMFCApplication71View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	point1.x = point.x;
	point1.y = point.y;
	Invalidate();
	
}


void CMFCApplication71View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCApplication71Doc* pDoc = GetDocument();
	CClientDC dc(this);
	if (m = false) {

		//point1.x = point.x;              //记录鼠标抬起的位置
		//point1.y = point.y;
		//InvalidateRect(NULL, TRUE);//重绘矩形
		Invalidate();
		m = false;
	}

	CView::OnLButtonUp(nFlags, point);
}
