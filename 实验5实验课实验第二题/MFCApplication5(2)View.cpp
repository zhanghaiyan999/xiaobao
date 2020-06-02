
// MFCApplication5(2)View.cpp: CMFCApplication52View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication5(2).h"
#endif

#include "MFCApplication5(2)Doc.h"
#include "MFCApplication5(2)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication52View

IMPLEMENT_DYNCREATE(CMFCApplication52View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication52View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMFCApplication52View 构造/析构

CMFCApplication52View::CMFCApplication52View() noexcept
{
	// TODO: 在此处添加构造代码
	BITMAP BM;//位图区大小
	m_Bitmap.LoadBitmap(IDB_BITMAP1);//是正确的
	m_Bitmap.GetBitmap(&BM);//获得位图区的大小
	m_nWidth = BM.bmWidth;//获得位图区的宽度
	m_nHeight = BM.bmHeight;//获得位图区的高度






}

CMFCApplication52View::~CMFCApplication52View()
{
}

BOOL CMFCApplication52View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication52View 绘图

void CMFCApplication52View::OnDraw(CDC* pDC)
{
	CMFCApplication52Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CDC MemDC;//位图内存
	MemDC.CreateCompatibleDC(NULL);//拷到客户区内存DC里面
	MemDC.SelectObject(m_Bitmap);
	pDC->BitBlt(0, 0, m_nWidth, m_nHeight, &MemDC, 0, 0, SRCCOPY);//调用CDC，一块一块的转移，以SRCCOPY拷贝

}

void CMFCApplication52View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCApplication52View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCApplication52View 诊断

#ifdef _DEBUG
void CMFCApplication52View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication52View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication52Doc* CMFCApplication52View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication52Doc)));
	return (CMFCApplication52Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication52View 消息处理程序
