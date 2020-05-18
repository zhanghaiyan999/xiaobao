
// MFCApplicatio2View.cpp: CMFCApplicatio2View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplicatio2.h"
#endif

#include "MFCApplicatio2Doc.h"
#include "MFCApplicatio2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplicatio2View

IMPLEMENT_DYNCREATE(CMFCApplicatio2View, CView)

BEGIN_MESSAGE_MAP(CMFCApplicatio2View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCApplicatio2View 构造/析构

CMFCApplicatio2View::CMFCApplicatio2View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFCApplicatio2View::~CMFCApplicatio2View()
{
}

BOOL CMFCApplicatio2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplicatio2View 绘图

void CMFCApplicatio2View::OnDraw(CDC* pDC)
{
	CMFCApplicatio2Doc* pDoc = GetDocument();//文档类指针
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString strcount;
	strcount.Format(L"计数 %d",pDoc->count);
	pDC->TextOutW(20, 20, strcount);
	// TODO: 在此处为本机数据添加绘制代码
	//CString strcount;
	//strcount.Format(L"%d", pDoc->count);
	
	
	//pDC->TextOutW(20, 20, strcount);
}

void CMFCApplicatio2View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCApplicatio2View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCApplicatio2View 诊断

#ifdef _DEBUG
void CMFCApplicatio2View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplicatio2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplicatio2Doc* CMFCApplicatio2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplicatio2Doc)));
	return (CMFCApplicatio2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplicatio2View 消息处理程序


void CMFCApplicatio2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCApplicatio2Doc* pDoc = GetDocument();//文档类指针
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString t;
	t.Format(_T("点的位置是（%d,%d）"), point.x, point.y);

	CClientDC dc(this);
	dc.TextOutW(100, 200, t);
	++pDoc->count;
	CView::OnLButtonDown(nFlags, point);//获取鼠标点击的位置
}


void CMFCApplicatio2View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCApplicatio2Doc* pDoc = GetDocument();//文档类指针
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	Invalidate();//刷新
	CView::OnRButtonDown(nFlags, point);
}
