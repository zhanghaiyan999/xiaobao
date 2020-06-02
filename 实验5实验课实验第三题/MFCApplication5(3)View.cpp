
// MFCApplication5(3)View.cpp: CMFCApplication53View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication5(3).h"
#endif

#include "MFCApplication5(3)Doc.h"
#include "MFCApplication5(3)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication53View

IMPLEMENT_DYNCREATE(CMFCApplication53View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication53View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_32773, &CMFCApplication53View::On32773)
	ON_COMMAND(ID_32774, &CMFCApplication53View::On32774)
	ON_COMMAND(ID_32775, &CMFCApplication53View::On32775)
END_MESSAGE_MAP()

// CMFCApplication53View 构造/析构

CMFCApplication53View::CMFCApplication53View() noexcept
{
	// TODO: 在此处添加构造代码
	
	startPoint = 0;
	OldPoint = 0;
	startRect = FALSE;
}

CMFCApplication53View::~CMFCApplication53View()
{
}

BOOL CMFCApplication53View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication53View 绘图

void CMFCApplication53View::OnDraw(CDC* pDC)
{
	CMFCApplication53Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	
}

void CMFCApplication53View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCApplication53View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCApplication53View 诊断

#ifdef _DEBUG
void CMFCApplication53View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication53View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication53Doc* CMFCApplication53View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication53Doc)));
	return (CMFCApplication53Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication53View 消息处理程序


void CMFCApplication53View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	startRect = TRUE; //鼠标左键单击，设置可以开始绘制矩形框
	startPoint = point; //以鼠标点击记录起始点
	OldPoint = point;//设置老点也为起始点
	
	CView::OnLButtonDown(nFlags, point);
}


void CMFCApplication53View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this); //获取设备句柄
	dc.SetROP2(R2_NOT);//此为关键
	dc.SetROP2(R2_NOT);//所绘制的图形并没有消失，所以可以验证下面的连续两次颜色取反不是在一次相应中完成
	//SetRop2 Specifies the new drawing mode.(MSDN)
		 //R2_NOT   Pixel is the inverse of the screen color.(MSDN)
		 //即：该函数用来定义绘制的颜色，而该参数则将颜色设置为原屏幕颜色的反色
	//这样，如果连续绘制两次的话，就可以恢复原来屏幕的颜色了（如下）
	//但是，这里的连续两次绘制却不是在一次消息响应中完成的
	//而是在第一次拖动响应的绘制可以显示（也就是看到的），第二次拖动绘制实现擦出（也就看不到了）

	dc.SelectStockObject(NULL_BRUSH);//不使用画刷*/
	if (TRUE == startRect) //根据是否有单击判断是否可以画矩形
	{
	switch (flag)
	{
	case 1: //Line

	//擦去上一次绘制的临时线
		dc.MoveTo(startPoint);
		dc.LineTo(OldPoint);

		//绘制这一次的临时线
		dc.MoveTo(startPoint);
		dc.LineTo(point);

		//将临时线的终点复制给OldPoint，
		//使其在消息循环的过程中将该值传递到
		//擦去上一次画线的过程中，以便擦去上一次所画的线
		OldPoint = point;
		break;

	case 2://Rectangle


		dc.Rectangle(CRect(startPoint, OldPoint));
		dc.Rectangle(CRect(startPoint, point));
		OldPoint = point;

		break;


	case 3:  //Ellipse


		dc.Ellipse(CRect(startPoint, OldPoint));
		dc.Ellipse(CRect(startPoint, point));
		OldPoint = point;
		break;
	case 4:   //deault

		break;

	}
}

	CView::OnMouseMove(nFlags, point);
}

void CMFCApplication53View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	startRect = FALSE;//重置绘制矩形框标志,消隐最后的一个矩形,消隐最后的一个矩形
	CClientDC dc(this);//获取设备句柄
	switch (flag)
	{

	case 1:  //Line

  //擦去MouseMove消息响应中绘制的最后一次临时线
		dc.MoveTo(startPoint);
		dc.LineTo(OldPoint);

		//绘制固定线
		dc.MoveTo(startPoint);
		dc.LineTo(point);
		break;
	case 2: //Retangle

	//利用当前画刷绘制矩形，内部由当前空画刷（NULL_BRUSH）填充。
	//擦去MouseMove消息响应中的临时矩形
		dc.Rectangle(CRect(startPoint, OldPoint));
		//绘制固定矩形
		dc.Rectangle(CRect(startPoint, point));
		break;
	case 3:  //Ellipse

		dc.Ellipse(CRect(startPoint, OldPoint));
		dc.Ellipse(CRect(startPoint, point));
		break;
	case 4:  //deault

		break;

	}
	
	CView::OnLButtonUp(nFlags, point);
}


void CMFCApplication53View::On32773()//画线事件处理程序
{
	// TODO: 在此添加命令处理程序代码
	
	flag = 1;
	


}
void CMFCApplication53View::On32774()//画矩形事件处理程序
{
	// TODO: 在此添加命令处理程序代码
	flag = 2;
}
void CMFCApplication53View::On32775()//画椭圆事件处理程序
{
	// TODO: 在此添加命令处理程序代码
	flag = 3;
}
