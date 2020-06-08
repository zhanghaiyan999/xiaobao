
// MFCApplication8View.cpp: CMFCApplication8View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication8.h"
#endif
#include"MyDlg.h"
#include "MFCApplication8Doc.h"
#include "MFCApplication8View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication8View

IMPLEMENT_DYNCREATE(CMFCApplication8View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication8View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_32771, &CMFCApplication8View::On32771)
END_MESSAGE_MAP()

// CMFCApplication8View 构造/析构

CMFCApplication8View::CMFCApplication8View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFCApplication8View::~CMFCApplication8View()
{
}

BOOL CMFCApplication8View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication8View 绘图

void CMFCApplication8View::OnDraw(CDC* /*pDC*/)
{
	CMFCApplication8Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}

void CMFCApplication8View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCApplication8View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCApplication8View 诊断

#ifdef _DEBUG
void CMFCApplication8View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication8View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication8Doc* CMFCApplication8View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication8Doc)));
	return (CMFCApplication8Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication8View 消息处理程序


void CMFCApplication8View::On32771()
{
	// TODO: 在此添加命令处理程序代码
	MyDlg dlg;
	CClientDC dc(this);
	CPen newpen, *oldpen;
	CBrush newbrush, *oldbrush;
	

	int r = dlg.DoModal();
	if (r == IDOK) {
		
		newpen.CreatePen(PS_SOLID, 1, RGB(0, 255, 0));//dlg.n1, dlg.n2, dlg.n3
		oldpen = dc.SelectObject(&newpen);
		newbrush.CreateSolidBrush(RGB(dlg.n1, dlg.n2, dlg.n3));
		oldbrush = dc.SelectObject(&newbrush);
		CRect cr(dlg.x - dlg.b, dlg.y - dlg.a, dlg.x + dlg.b, dlg.y + dlg.a);
		dc.Ellipse(cr);
		dc.SelectObject(oldbrush);
		newbrush.DeleteObject();
		dc.SelectObject(oldpen);
		newpen.DeleteObject();
	}
}
