
// MFCApplication7(4)View.cpp: CMFCApplication74View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication7(4).h"
#endif

#include "MFCApplication7(4)Doc.h"
#include "MFCApplication7(4)View.h"
#include "MyDlg0.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication74View

IMPLEMENT_DYNCREATE(CMFCApplication74View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication74View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_32771, &CMFCApplication74View::On32771)
END_MESSAGE_MAP()

// CMFCApplication74View 构造/析构

CMFCApplication74View::CMFCApplication74View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFCApplication74View::~CMFCApplication74View()
{
}

BOOL CMFCApplication74View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication74View 绘图

void CMFCApplication74View::OnDraw(CDC* /*pDC*/)
{
	CMFCApplication74Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}

void CMFCApplication74View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCApplication74View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCApplication74View 诊断

#ifdef _DEBUG
void CMFCApplication74View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication74View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication74Doc* CMFCApplication74View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication74Doc)));
	return (CMFCApplication74Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication74View 消息处理程序


void CMFCApplication74View::On32771()                //菜单
{
	// TODO: 在此添加命令处理程序代码
	MyDlg0 dlg;
	int t = dlg.DoModal();
	if (t == IDOK) {

	}
}
