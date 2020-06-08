
// MFCApplication8(2)View.cpp: CMFCApplication82View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication8(2).h"
#endif

#include "MFCApplication8(2)Doc.h"
#include "MFCApplication8(2)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication82View

IMPLEMENT_DYNCREATE(CMFCApplication82View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication82View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMFCApplication82View 构造/析构

CMFCApplication82View::CMFCApplication82View() noexcept
{
	// TODO: 在此处添加构造代码
	flag = false;
	Point = 0;
	oldpoint = 0;


}

CMFCApplication82View::~CMFCApplication82View()
{
}

BOOL CMFCApplication82View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication82View 绘图

void CMFCApplication82View::OnDraw(CDC* pDC)
{
	CMFCApplication82Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	//消隐最后的一个矩形（其原理跟拖动时矩形框绘制原理相同）
	CClientDC dc(this);
	dc.SetROP2(R2_NOT);
	dc.SelectStockObject(NULL_BRUSH);
	//dc.Rectangle(CRect(Point, oldpoint));
	//CRect(Point, oldpoint);
	//dc.Ellipse();
	CRect rect;
	this->GetClientRect(rect);
	int r = 50;
	int r1 = 80;
	CRect cr(Point.x - r1, Point.y - r1, oldpoint.x + r, oldpoint.y + r);
	dc.Ellipse(cr);
}

void CMFCApplication82View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCApplication82View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCApplication82View 诊断

#ifdef _DEBUG
void CMFCApplication82View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication82View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication82Doc* CMFCApplication82View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication82Doc)));
	return (CMFCApplication82Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication82View 消息处理程序


void CMFCApplication82View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	flag= TRUE;   //鼠标左键单击，设置可以开始绘制矩形框
	Point= point; //记录开始点
	oldpoint = point;   //设置老点也为开始点

	CView::OnLButtonDown(nFlags, point);
}


void CMFCApplication82View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CClientDC dc(this);   //获取设备句柄

	//SetRop2 Specifies the new drawing mode.(MSDN)
	//R2_NOT   Pixel is the inverse of the screen color.(MSDN)
	//即：该函数用来定义绘制的颜色，而该参数则将颜色设置为原屏幕颜色的反色
	//这样，如果连续绘制两次的话，就可以恢复原来屏幕的颜色了（如下）
	//但是，这里的连续两次绘制却不是在一次消息响应中完成的
	//而是在第一次拖动响应的绘制可以显示（也就是看到的），第二次拖动绘制实现擦出（也就看不到了）
	dc.SetROP2(R2_NOT);   //此为关键!!!如果设置为R2_XORPEN 则为画笔的反色
	dc.SelectStockObject(NULL_BRUSH); //不使用画刷
	CRect rect;
	this->GetClientRect(rect);
	int r = 50;
	int r1 = 80;
	
	if (flag==true)   //根据是否有单击判断是否可以画矩形
	{
		CRect cr(Point.x - r1, Point.y - r1, oldpoint.x + r, oldpoint.y + r);
		dc.Ellipse(cr);
		oldpoint = point;
	}

	CView::OnMouseMove(nFlags, point);
}


void CMFCApplication82View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	flag = FALSE; //重置绘制矩形框标志

	Invalidate();

	CView::OnLButtonUp(nFlags, point);
}
