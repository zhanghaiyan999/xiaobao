
// MFCApplication4(2)View.cpp: CMFCApplication42View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication4(2).h"
#endif

#include "MFCApplication4(2)Doc.h"
#include "MFCApplication4(2)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication42View

IMPLEMENT_DYNCREATE(CMFCApplication42View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication42View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCApplication42View 构造/析构

CMFCApplication42View::CMFCApplication42View() noexcept
{
	// TODO: 在此处添加构造代码
	
	
}

CMFCApplication42View::~CMFCApplication42View()
{
}

BOOL CMFCApplication42View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication42View 绘图

void CMFCApplication42View::OnDraw(CDC* pDC)
{
	CMFCApplication42Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: 在此处为本机数据添加绘制代码
	this->GetClientRect(&pDoc->rect);
	if (pDoc->set) {
		pDoc->cr.left = (pDoc->rect.right - pDoc->rect.left) / 2 - 100; pDoc->cr.top = (pDoc->rect.bottom - pDoc->rect.top) / 2 - 100;

		pDoc->cr.right = (pDoc->rect.right - pDoc->rect.left) / 2 + 100; pDoc->cr.bottom = (pDoc->rect.bottom - pDoc->rect.top) / 2 + 100;

		pDC->Rectangle(pDoc->cr);
	}
	pDoc->set = false;
	pDC->Rectangle(pDoc->cr);
	
}

void CMFCApplication42View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCApplication42View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCApplication42View 诊断

#ifdef _DEBUG
void CMFCApplication42View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication42View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication42Doc* CMFCApplication42View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication42Doc)));
	return (CMFCApplication42Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication42View 消息处理程序


void CMFCApplication42View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)//nFlags掩码
{
	
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCApplication42Doc* pDoc = GetDocument();
	CClientDC dc(this);//获得客户区
	CRect rect;
	
	switch (nChar)
	{
	case VK_LEFT:
		if (pDoc->cr.left > 0)                    //向左移动
		{
			pDoc->cr.left -= 5;
			pDoc->cr.right -= 5;
		}
		break;
	case VK_RIGHT:
		if (pDoc->cr.right <= (pDoc->rect.right - pDoc->rect.left))//向右移动
		{
			pDoc->cr.left += 5;
			pDoc->cr.right += 5;
		}
			break;
	case VK_UP:
		if (pDoc->cr.top > 0)//向上移动
		{  
			pDoc->cr.top -= 5;
			pDoc->cr.bottom-= 5;
			
		}
		break;
	case VK_DOWN:
		if (pDoc->cr.bottom <= (pDoc->rect.bottom - pDoc->rect.top))//向下移动
		{
			pDoc->cr.top += 5;
			pDoc->cr.bottom += 5;
			
		}
		break;
	case VK_HOME:
		if (pDoc->cr.left > 0 && pDoc->cr.top > 0)//左上角增大
		{
			pDoc->cr.left-= 5;
			pDoc->cr.top-= 5;

		}
		break;
	case VK_END:
		if (pDoc->cr.right>0 && pDoc->cr.bottom > 0)//右下角缩小
		{
			pDoc->cr.right-= 5;
			pDoc->cr.bottom -= 5;

		}
		break;

		}
		InvalidateRect(NULL, TRUE);  //强制重绘
	
	

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CMFCApplication42View::OnLButtonDown(UINT nFlags, CPoint point)   //当按下左键的时候，矩形恢复到原来的大小
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCApplication42Doc* pDoc = GetDocument();
	GetClientRect(&pDoc->rect);
	if (nFlags)
	{

	
		pDoc->cr.left = (pDoc->rect.right - pDoc->rect.left) / 2 - 100; pDoc->cr.top = (pDoc->rect.bottom - pDoc->rect.top) / 2 - 100;

		pDoc->cr.right = (pDoc->rect.right - pDoc->rect.left) / 2 + 100; pDoc->cr.bottom = (pDoc->rect.bottom - pDoc->rect.top) / 2 + 100;
		

	}
	InvalidateRect(NULL, TRUE);
	
	CView::OnLButtonDown(nFlags, point);
}
