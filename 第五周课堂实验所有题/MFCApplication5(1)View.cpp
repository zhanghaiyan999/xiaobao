
// MFCApplication5(1)View.cpp: CMFCApplication51View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication5(1).h"
#endif

#include "MFCApplication5(1)Doc.h"
#include "MFCApplication5(1)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication51View

IMPLEMENT_DYNCREATE(CMFCApplication51View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication51View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_32771, &CMFCApplication51View::On32771)
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMFCApplication51View 构造/析构

CMFCApplication51View::CMFCApplication51View() noexcept
{
	// TODO: 在此处添加构造代码
	set = true;

}

CMFCApplication51View::~CMFCApplication51View()
{
}

BOOL CMFCApplication51View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication51View 绘图

void CMFCApplication51View::OnDraw(CDC* pDC)
{
	CMFCApplication51Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
/*	CBrush oldbrush, newbrush;
	newbrush.CreateSolidBrush(RGB(200, 0, 0));
	oldbrush =pDC-> SelectObject(&newbrush);
	*/
	


}

void CMFCApplication51View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCApplication51View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCApplication51View 诊断

#ifdef _DEBUG
void CMFCApplication51View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication51View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication51Doc* CMFCApplication51View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication51Doc)));
	return (CMFCApplication51Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication51View 消息处理程序

void a() {
	while (1) {
		Sleep(10000);
	}
}
void CMFCApplication51View::On32771()         //渐变圆
{
	// TODO: 在此添加命令处理程序代码

	CMFCApplication51Doc* pDoc = GetDocument();

	CPoint point, cpoint;
	CRect cr;
	this->GetClientRect(&cr);//获得客户区的矩形
	CClientDC dc(this);
	cpoint.x = (cr.left + cr.right) / 2;
	cpoint.y = (cr.bottom + cr.top) / 2;
	int r = (cr.right - cr.left) / 100;
	
	
	
	for (int r = (cr.right - cr.left) / 1000000; r <= ((cr.bottom - cr.top) / 2); r++)//r++,半径由小变大
	{   
		
		CBrush brush(RGB(250, 0, 0));
		CBrush *oldbrush; //定义画刷
		oldbrush =dc.SelectObject(&brush);//把新画刷放入老画刷
		

		CRect rect(cpoint.x - r, cpoint.y - r, cpoint.x + r, cpoint.y + r);//画椭圆
		dc.Ellipse(&rect);
		dc.SelectObject(oldbrush);//将原来的画刷选回去
	

	    HANDLE hThread;
		DWORD threadID;
		hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)a, NULL, 0, &threadID);//sleep函数		
	}
	
	// TODO: 在此处为本机数据添加绘制代码
	
	
}



void CMFCApplication51View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	CView::OnLButtonDown(nFlags, point);
}


void CMFCApplication51View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int r = nIDEvent;
	CRect rect;
	this->GetClientRect(&rect);


	CView::OnTimer(nIDEvent);
}
