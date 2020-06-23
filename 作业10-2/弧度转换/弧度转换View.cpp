
// 弧度转换View.cpp : C弧度转换View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "弧度转换.h"
#endif

#include "弧度转换Doc.h"
#include "弧度转换View.h"
#include"convert.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C弧度转换View

IMPLEMENT_DYNCREATE(C弧度转换View, CView)

BEGIN_MESSAGE_MAP(C弧度转换View, CView)
END_MESSAGE_MAP()

// C弧度转换View 构造/析构

C弧度转换View::C弧度转换View()
{
	// TODO: 在此处添加构造代码

}

C弧度转换View::~C弧度转换View()
{
}

BOOL C弧度转换View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C弧度转换View 绘制

void C弧度转换View::OnDraw(CDC* pDC)
{
	C弧度转换Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: 在此处为本机数据添加绘制代码
	F2 xx;
	CString C;
	C.Format(_T("转换后的弧度为：%f"), xx.convert(30.0));
	pDC->TextOutW(200, 200, C);

}


// C弧度转换View 诊断

#ifdef _DEBUG
void C弧度转换View::AssertValid() const
{
	CView::AssertValid();
}

void C弧度转换View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C弧度转换Doc* C弧度转换View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C弧度转换Doc)));
	return (C弧度转换Doc*)m_pDocument;
}
#endif //_DEBUG


// C弧度转换View 消息处理程序
