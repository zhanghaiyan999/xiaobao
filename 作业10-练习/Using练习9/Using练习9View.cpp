
// Using练习9View.cpp : CUsing练习9View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Using练习9.h"
#endif

#include "Using练习9Doc.h"
#include "Using练习9View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include"w32.h"
#include"Win32D.h"

// CUsing练习9View

IMPLEMENT_DYNCREATE(CUsing练习9View, CView)

BEGIN_MESSAGE_MAP(CUsing练习9View, CView)
END_MESSAGE_MAP()

// CUsing练习9View 构造/析构

CUsing练习9View::CUsing练习9View()
{
	// TODO: 在此处添加构造代码

}

CUsing练习9View::~CUsing练习9View()
{
}

BOOL CUsing练习9View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CUsing练习9View 绘制

void CUsing练习9View::OnDraw(CDC* pDC)
{
	CUsing练习9Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)

		return;

	// TODO: 在此处为本机数据添加绘制代码
	CString S;
	S = CString(pchar());
	pDC->TextOutW(200, 300, S);
	CString C;
	C.Format(_T("%d"), )
	CString A;
	A.Format(_T("%d,这是从动态链接库取得的返回值"), GetInt());
	pDC->TextOutW(200, 200, A);
}


// CUsing练习9View 诊断

#ifdef _DEBUG
void CUsing练习9View::AssertValid() const
{
	CView::AssertValid();
}

void CUsing练习9View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CUsing练习9Doc* CUsing练习9View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CUsing练习9Doc)));
	return (CUsing练习9Doc*)m_pDocument;
}
#endif //_DEBUG


// CUsing练习9View 消息处理程序
