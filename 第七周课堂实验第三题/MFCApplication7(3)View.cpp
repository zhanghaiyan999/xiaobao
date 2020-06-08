
// MFCApplication7(3)View.cpp: CMFCApplication73View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication7(3).h"
#endif

#include "MFCApplication7(3)Doc.h"
#include "MFCApplication7(3)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication73View

IMPLEMENT_DYNCREATE(CMFCApplication73View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication73View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMFCApplication73View 构造/析构

CMFCApplication73View::CMFCApplication73View() noexcept
{
	// TODO: 在此处添加构造代码
	N = 1;
	ca.SetSize(256);
	
	
}

CMFCApplication73View::~CMFCApplication73View()
{
}

BOOL CMFCApplication73View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication73View 绘图

void CMFCApplication73View::OnDraw(CDC* pDC)
{
	CMFCApplication73Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CRect cr;
	this->GetClientRect(cr);

	point1.y = (cr.bottom - cr.top) / 2;
	point1.x = (cr.bottom - cr.top) / 2 - 200;

	r = (cr.bottom - cr.top) / 2 - 200;
	CRect rect(point1.x - r, point1.y - r, point1.x + r, point1.y + r);

	ca.Add(rect);
	
	for (int i = 0; i < ca.GetSize(); i++)
	{
		pDC->Ellipse(ca.GetAt(i));
	}
}

void CMFCApplication73View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCApplication73View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCApplication73View 诊断

#ifdef _DEBUG
void CMFCApplication73View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication73View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication73Doc* CMFCApplication73View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication73Doc)));
	return (CMFCApplication73Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication73View 消息处理程序


void CMFCApplication73View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (nFlags) {
		set = true;
	}
	


	InvalidateRect(NULL, TRUE);

	CView::OnLButtonDown(nFlags, point);
}


void CMFCApplication73View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	CRect cr;
	this->GetClientRect(cr);
	point1.y = (cr.bottom - cr.top) / 2;
	point1.x = (cr.bottom - cr.top) / 2 - 200;

	r = (cr.bottom - cr.top) / 2 - 200;
	CRect rect(point1.x - r, point1.y - r, point1.x + r, point1.y + r);

	ca.Add(rect);
	int i = nIDEvent;
	
	this->GetClientRect(&rect);
	if (set)
	{
		for (int i = 0; i <= N; i++)
		{
			SetTimer(i, rand() % 400 + 10, NULL);               //设置开始进程
			dc.Ellipse(ca.GetAt(i));
			set = false;                          //当一个进程结束的时候就结束false

		}

	}
	if (cr.right - ca[i].right <= 0)
	{
		a[i] = 1;
	}
	if (a[i] != 1)
	{
		ca[i].left+= 10;                 //矩形增加右边长
		ca[i].right += 10;

	}
	else if (a[i] == 1)
	{
		ca[i].left -= 10;
		ca[i].right -= 10;              //矩形增加左边长	
	}
	

	this->Invalidate();             //刷新
	

	CView::OnTimer(nIDEvent);
}
