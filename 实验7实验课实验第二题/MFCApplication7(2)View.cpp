
// MFCApplication7(2)View.cpp: CMFCApplication72View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication7(2).h"
#endif

#include "MFCApplication7(2)Doc.h"
#include "MFCApplication7(2)View.h"
#include"MyDlg0.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication72View

IMPLEMENT_DYNCREATE(CMFCApplication72View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication72View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_32771, &CMFCApplication72View::On32771)
END_MESSAGE_MAP()

// CMFCApplication72View 构造/析构

CMFCApplication72View::CMFCApplication72View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFCApplication72View::~CMFCApplication72View()
{
}

BOOL CMFCApplication72View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication72View 绘图

void CMFCApplication72View::OnDraw(CDC* /*pDC*/)
{
	CMFCApplication72Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}

void CMFCApplication72View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCApplication72View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCApplication72View 诊断

#ifdef _DEBUG
void CMFCApplication72View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication72View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication72Doc* CMFCApplication72View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication72Doc)));
	return (CMFCApplication72Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication72View 消息处理程序


void CMFCApplication72View::On32771()
{
	// TODO: 在此添加命令处理程序代码
	MyDlg0 dlg;
	int t = dlg.DoModal();
	if (t == IDOK) {

	}
}
