
// shiyan2(3)View.cpp: Cshiyan23View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "shiyan2(3).h"
#endif

#include "shiyan2(3)Doc.h"
#include "shiyan2(3)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cshiyan23View

IMPLEMENT_DYNCREATE(Cshiyan23View, CView)

BEGIN_MESSAGE_MAP(Cshiyan23View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// Cshiyan23View 构造/析构

Cshiyan23View::Cshiyan23View() noexcept
{
	// TODO: 在此处添加构造代码

}

Cshiyan23View::~Cshiyan23View()
{
}

BOOL Cshiyan23View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cshiyan23View 绘图

void Cshiyan23View::OnDraw(CDC* pDC)
{
	Cshiyan23Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CRect rect;
	this->GetClientRect(rect);//整个客户区的坐标，原点为客户区的左上角，获取窗口尺寸
	CBrush brush(RGB(250, 0, 0));
	CBrush *oldbrush; //定义画刷
	oldbrush = pDC->SelectObject(&brush);//把新画刷放入老画刷
	pDC->Ellipse(rect);//画椭圆
	pDC->SelectObject(oldbrush);//将原来的画刷选回去
	ReleaseDC(pDC);//释放DC
	
	
}

void Cshiyan23View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Cshiyan23View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Cshiyan23View 诊断

#ifdef _DEBUG
void Cshiyan23View::AssertValid() const
{
	CView::AssertValid();
}

void Cshiyan23View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cshiyan23Doc* Cshiyan23View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cshiyan23Doc)));
	return (Cshiyan23Doc*)m_pDocument;
}
#endif //_DEBUG


// Cshiyan23View 消息处理程序


void Cshiyan23View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CRect cr;
	this->GetClientRect(cr);//获取客户区的尺寸
	point.x = cr.left + (cr.right - cr.left) / 2;           //确定客户区的范围
	point.y = cr.top + (cr.bottom - cr.top) / 2;
	int r;
	if ((cr.right - cr.left) > cr.bottom - cr.top)
		r = (cr.bottom - cr.top);                         //确定客户区的中心
	else
		r = (cr.right - cr.left);
	
	CRect rect(point.x - r, point.y - r, point.x + r, point.y + r);//画椭圆
	
	this->Invalidate();
	CView::OnLButtonDown(nFlags, point);
}
