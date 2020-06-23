
// 动态链接View.cpp : C动态链接View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "动态链接.h"
#endif

#include "动态链接Doc.h"
#include "动态链接View.h"
#include"作业9-3.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C动态链接View

IMPLEMENT_DYNCREATE(C动态链接View, CView)

BEGIN_MESSAGE_MAP(C动态链接View, CView)
END_MESSAGE_MAP()

// C动态链接View 构造/析构

C动态链接View::C动态链接View()
{
	// TODO: 在此处添加构造代码

}

C动态链接View::~C动态链接View()
{
}

BOOL C动态链接View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C动态链接View 绘制

void C动态链接View::OnDraw(CDC* pDC)
{
	C动态链接Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CString X, XX, XXX;
	X.Format(_T("%d这个数可以使用"), GetNum(pDoc->n));
	if (Factorial(pDoc->n) > 2147483647)
	{
		XX.Format(_T("该数的阶乘已溢出"));
	}
	else
	{
XX.Format(_T("该数的阶乘为：%d"), Factorial(pDoc->n));
	}

	XXX.Format(_T("该数的弧度为：%f"), convert(30.0));
	pDC->TextOutW(200, 200, X);
	pDC->TextOutW(200, 250, XX);
	pDC->TextOutW(200, 300, XXX);


}


// C动态链接View 诊断

#ifdef _DEBUG
void C动态链接View::AssertValid() const
{
	CView::AssertValid();
}

void C动态链接View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C动态链接Doc* C动态链接View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C动态链接Doc)));
	return (C动态链接Doc*)m_pDocument;
}
#endif //_DEBUG


// C动态链接View 消息处理程序
