
// 实现阶乘View.cpp : C实现阶乘View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "实现阶乘.h"
#endif

#include "实现阶乘Doc.h"
#include "实现阶乘View.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include"阶乘.h"

// C实现阶乘View

IMPLEMENT_DYNCREATE(C实现阶乘View, CView)

BEGIN_MESSAGE_MAP(C实现阶乘View, CView)
END_MESSAGE_MAP()

// C实现阶乘View 构造/析构

C实现阶乘View::C实现阶乘View()
{
	// TODO: 在此处添加构造代码

}

C实现阶乘View::~C实现阶乘View()
{
}

BOOL C实现阶乘View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C实现阶乘View 绘制

void C实现阶乘View::OnDraw(CDC* pDC)
{
	C实现阶乘Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString S,SS;
	//S = CString(pchar());
	//pDC->TextOutW(200, 200, S);
	F2 b;
	S.Format(_T("%d 该数可以使用"), b.GetNum(pDoc->n));
	if (b.Factorial(pDoc->n) > 50000)
	{
		SS.Format(_T("该数过大已溢出"));
	}
	else
	{
SS.Format(_T("该数阶乘的结果为：%d"),b.Factorial(pDoc->n)); 

	}
		pDC->TextOutW(300, 200, S);
	pDC->TextOutW(300, 300, SS);

	// TODO: 在此处为本机数据添加绘制代码
}


// C实现阶乘View 诊断

#ifdef _DEBUG
void C实现阶乘View::AssertValid() const
{
	CView::AssertValid();
}

void C实现阶乘View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C实现阶乘Doc* C实现阶乘View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C实现阶乘Doc)));
	return (C实现阶乘Doc*)m_pDocument;
}
#endif //_DEBUG


// C实现阶乘View 消息处理程序
