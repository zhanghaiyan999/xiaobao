
// MFCApplication4(3)View.cpp: CMFCApplication43View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication4(3).h"
#endif

#include "MFCApplication4(3)Doc.h"
#include "MFCApplication4(3)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication43View

IMPLEMENT_DYNCREATE(CMFCApplication43View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication43View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMFCApplication43View 构造/析构

CMFCApplication43View::CMFCApplication43View() noexcept
{
	// TODO: 在此处添加构造代码
	set = true;
	N = 5;
	for (int i = 0; i < N; i++)
	{
		int t = (i + 1) * 100;
		CRect rect(t, 0, t + 20, 20);
		cr.Add(rect);

	}

}

CMFCApplication43View::~CMFCApplication43View()
{
}

BOOL CMFCApplication43View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication43View 绘图

void CMFCApplication43View::OnDraw(CDC* pDC)
{
	CMFCApplication43Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	if (set)
	{
		for (int i = 0; i < N; i++)
		{
			SetTimer(i, rand() % 400 + 100, NULL);               //设置开始进程
			pDC->Ellipse(cr[i]);
			set = false;                               //当一个进程结束的时候就结束false

		}
	}
	for (int i = 0; i < N; i++)
	{
		pDC->Ellipse(cr[i]);                //在客户区画5个矩形
	}
	
}

void CMFCApplication43View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCApplication43View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCApplication43View 诊断

#ifdef _DEBUG
void CMFCApplication43View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication43View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication43Doc* CMFCApplication43View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication43Doc)));
	return (CMFCApplication43Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication43View 消息处理程序


void CMFCApplication43View::OnTimer(UINT_PTR nIDEvent)//nIDEvent第i个项目进行
{
	CMFCApplication43Doc* pDoc = GetDocument();
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int i = nIDEvent;
	CRect rect;
	this->GetClientRect(&rect);
	//int a[] = { 0,0,0,0,0 };
	if (rect.bottom - cr[i].bottom <= 0)
	{
		pDoc->a[i] = 1;
	}
	if (pDoc->a[i]!= 1)
	{
		cr[i].top += 100;                 //矩形增加上边长
		cr[i].bottom += 100;

	}
    else if (pDoc->a[i]==1 )
	{
		cr[i].top -= 100;                 //矩形增加上边长
		cr[i].bottom -= 100;              //矩形增加下边长	
	}
	


	/*	if (cr[i].bottom <= rect.bottom)
		{

			cr[i].top += 10;                 //矩形增加上边长
			cr[i].bottom += 10;              //矩形增加下边长	
			
		}
		else if ((cr[i].bottom >=rect.bottom) && cr[i].bottom>=0)
				{
					cr[i].top -= 100;                 //矩形增加上边长
					cr[i].bottom -= 100;
					
				}
				*/

	  this->Invalidate();             //刷新


	CView::OnTimer(nIDEvent);
}
