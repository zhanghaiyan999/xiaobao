
// 作业8-1View.cpp : C作业81View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "作业8-1.h"
#endif

#include "作业8-1Doc.h"
#include "作业8-1View.h"
#include "Studentlist.h"
#include<fstream>
#include<string>
#include<iostream>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C作业81View

IMPLEMENT_DYNCREATE(C作业81View, CView)

BEGIN_MESSAGE_MAP(C作业81View, CView)
	ON_COMMAND(ID_VIEW_STUDENTLIST, &C作业81View::OnViewStudentlist)
END_MESSAGE_MAP()

// C作业81View 构造/析构

C作业81View::C作业81View()
{
	// TODO: 在此处添加构造代码

}

C作业81View::~C作业81View()
{
}

BOOL C作业81View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C作业81View 绘制

void C作业81View::OnDraw(CDC* /*pDC*/)
{
	C作业81Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// C作业81View 诊断

#ifdef _DEBUG
void C作业81View::AssertValid() const
{
	CView::AssertValid();
}

void C作业81View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C作业81Doc* C作业81View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C作业81Doc)));
	return (C作业81Doc*)m_pDocument;
}
#endif //_DEBUG


// C作业81View 消息处理程序


void C作业81View::OnViewStudentlist()
{
	// TODO: 在此添加命令处理程序代码
	Studentlist cp;
	int r = cp.DoModal();
	if (r == IDCANCEL)
	{
		CFileDialog cfd(false);
		int x = cfd.DoModal();
		if (x == IDOK)
		{
			CString filename = cfd.GetPathName();
			ofstream ofs(filename);
			CString s ;
			int x=cp.list.GetCount();
			for (int i = 0; i < x; i++)
			{
				cp.list.GetText(i,s);
				string str;
				str = CStringA(s);

				ofs << s << endl;
			}
			//cp.list.GetText(1, s);
			//File.WriteString(s);
			//File.Close();


		}


	}
}
