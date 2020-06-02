
// MFCApplication5class(1)View.cpp: CMFCApplication5class1View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication5class(1).h"
#endif

#include "MFCApplication5class(1)Doc.h"
#include "MFCApplication5class(1)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication5class1View

IMPLEMENT_DYNCREATE(CMFCApplication5class1View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication5class1View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_SHOWNAME, &CMFCApplication5class1View::OnShowname)//id和菜单命令处理函数联系起来
END_MESSAGE_MAP()

// CMFCApplication5class1View 构造/析构

CMFCApplication5class1View::CMFCApplication5class1View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFCApplication5class1View::~CMFCApplication5class1View()
{
}

BOOL CMFCApplication5class1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication5class1View 绘图

void CMFCApplication5class1View::OnDraw(CDC* /*pDC*/)
{
	CMFCApplication5class1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}

void CMFCApplication5class1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCApplication5class1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCApplication5class1View 诊断

#ifdef _DEBUG
void CMFCApplication5class1View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication5class1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication5class1Doc* CMFCApplication5class1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication5class1Doc)));
	return (CMFCApplication5class1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication5class1View 消息处理程序


void CMFCApplication5class1View::OnShowname()
{
	// TODO: 在此添加命令处理程序代码
	CString s=_T("张海雁");
	CClientDC dc(this);
	dc.TextOutW(200, 300, s);


}
