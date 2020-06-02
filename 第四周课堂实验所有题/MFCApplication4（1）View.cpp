
// MFCApplication4（1）View.cpp: CMFCApplication41View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication4（1）.h"
#endif

#include "MFCApplication4（1）Doc.h"
#include "MFCApplication4（1）View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication41View

IMPLEMENT_DYNCREATE(CMFCApplication41View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication41View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMFCApplication41View 构造/析构

CMFCApplication41View::CMFCApplication41View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFCApplication41View::~CMFCApplication41View()
{
}

BOOL CMFCApplication41View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication41View 绘图

void CMFCApplication41View::OnDraw(CDC* pDC)
{
	CMFCApplication41Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->Rectangle(pDoc->m_tagRec);//客户区画矩形

}

void CMFCApplication41View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCApplication41View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCApplication41View 诊断

#ifdef _DEBUG
void CMFCApplication41View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication41View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication41Doc* CMFCApplication41View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication41Doc)));
	return (CMFCApplication41Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication41View 消息处理程序


void CMFCApplication41View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	CMFCApplication41Doc* pDoc = GetDocument();
	pDoc->m_tagRec.left= point.x;                    //记录鼠标按下的位置
	pDoc->m_tagRec.top= point.y;
	CView::OnLButtonDown(nFlags, point);
}


void CMFCApplication41View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCApplication41Doc* pDoc = GetDocument();
	CClientDC dc(this);
	pDoc->m_tagRec.right= point.x;              //记录鼠标抬起的位置
	pDoc->m_tagRec.bottom= point.y;
	InvalidateRect(NULL, TRUE);//重绘矩形

	CView::OnLButtonUp(nFlags, point);
}


void CMFCApplication41View::OnMouseMove(UINT nFlags, CPoint point)//记录移动次数
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCApplication41Doc* pDoc = GetDocument();
	CClientDC dc(this);//获取客户区
	CString s;
	s.Format(_T("X=%d ,Y=%d"), point.x, point.y);
	dc.TextOutW(200, 200, s);

	



	CView::OnMouseMove(nFlags, point);
}
