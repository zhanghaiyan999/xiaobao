
// MFCApplication6class(1)View.cpp: CMFCApplication6class1View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication6class(1).h"
#endif

#include "MFCApplication6class(1)Doc.h"
#include "MFCApplication6class(1)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication6class1View

IMPLEMENT_DYNCREATE(CMFCApplication6class1View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication6class1View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_FILE_OPEN, &CMFCApplication6class1View::OnFileOpen)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CMFCApplication6class1View 构造/析构

CMFCApplication6class1View::CMFCApplication6class1View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFCApplication6class1View::~CMFCApplication6class1View()
{
}

BOOL CMFCApplication6class1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication6class1View 绘图

void CMFCApplication6class1View::OnDraw(CDC* pDC)
{
	CMFCApplication6class1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码



}

void CMFCApplication6class1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCApplication6class1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCApplication6class1View 诊断

#ifdef _DEBUG
void CMFCApplication6class1View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication6class1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication6class1Doc* CMFCApplication6class1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication6class1Doc)));
	return (CMFCApplication6class1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication6class1View 消息处理程序


void CMFCApplication6class1View::OnFileOpen()//菜单命令处理函数
{
	// TODO: 在此添加命令处理程序代码
	CClientDC dc(this);

	CFileDialog cfd(true);//构造打开文件对话框的对象
	int r = cfd.DoModal();//首先打开文件对话框，r取得返回值
	CString filename = cfd.GetPathName();//取得文件对话框的路径名，赋给字符串
	dc.TextOutW(200, 300, filename);
	CImage img;//构造文件管理对象
	img.Load(filename);//载入
}


void CMFCApplication6class1View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CView::OnPaint()
    CFileDialog cfd(true);//构造打开文件对话框的对象
	int r = cfd.DoModal();//首先打开文件对话框，r取得返回值

	CString filename = cfd.GetPathName();//取得文件对话框的路径名，赋给字符串
	dc.TextOutW(200, 300, filename);
	CImage img;//构造文件管理对象
	img.Load(filename);//载入
	
	if (r == IDOK)
	{

	
		
		CRect rect;
		GetClientRect(&rect);//获得客户区的大小
		int w, h, sx, sy;//w,h是图像的高度和宽度，sx，sy是图像的左上角的位置
		{
			float rect_ratio = 1.0*rect.Width() / rect.Height();
			float img_ratio = 1.0*img.GetWidth() / img.GetHeight();

			if (rect_ratio > img_ratio)
			{
				h = rect.Height();
				w = img_ratio * h;
				sx = (rect.Width() - w) / 2;
				sy = 0;

			}
			else
			{
				w = rect.Width();
				h = w / img_ratio;
				sx = 0;
				sy = (rect.Height() - h) / 2;

			}
		}

		img.Draw(dc.m_hDC, sx, sy, w, h);//dc.m_hDC是句柄，图像显示
	}
	
}
