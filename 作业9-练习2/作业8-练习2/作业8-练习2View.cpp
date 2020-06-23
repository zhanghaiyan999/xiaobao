
// 作业8-练习2View.cpp : C作业8练习2View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "作业8-练习2.h"
#endif

#include "作业8-练习2Doc.h"
#include "作业8-练习2View.h"
#include "picture.h"
#include<fstream>
#include<string>
#include<iostream>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C作业8练习2View

IMPLEMENT_DYNCREATE(C作业8练习2View, CView)

BEGIN_MESSAGE_MAP(C作业8练习2View, CView)
	ON_COMMAND(ID_FILE_OPEN, &C作业8练习2View::OnFileOpen)
	ON_COMMAND(ID_FILE_SAVE, &C作业8练习2View::OnFileSave)
	ON_COMMAND(ID_FILE_SAVE_AS, &C作业8练习2View::OnFileSaveAs)
	ON_COMMAND(ID_SHOWPICTURE, &C作业8练习2View::OnShowpicture)
END_MESSAGE_MAP()

// C作业8练习2View 构造/析构

C作业8练习2View::C作业8练习2View()
{
	// TODO: 在此处添加构造代码

}

C作业8练习2View::~C作业8练习2View()
{
}

BOOL C作业8练习2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C作业8练习2View 绘制

void C作业8练习2View::OnDraw(CDC* /*pDC*/)
{
	C作业8练习2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// C作业8练习2View 诊断

#ifdef _DEBUG
void C作业8练习2View::AssertValid() const
{
	CView::AssertValid();
}

void C作业8练习2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C作业8练习2Doc* C作业8练习2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C作业8练习2Doc)));
	return (C作业8练习2Doc*)m_pDocument;
}
#endif //_DEBUG


// C作业8练习2View 消息处理程序


void C作业8练习2View::OnFileOpen()
{
	C作业8练习2Doc* pDoc = GetDocument();
	picture pc;

	CFileDialog cfd(true);  //建立对象
	int r = cfd.DoModal();  //弹出对话框
	CClientDC dc(this);
	if (r == IDOK)                   //如果退出对话框时选项为OK的话

	{
		CString filename = cfd.GetPathName();
		pDoc->B= filename;
		ifstream ifs(filename);
		string A;
		int x = 20, y = 10;
		while (ifs>>A)
		{
			dc.TextOutW(x, y, CString(A.c_str()));
			y += 30;
			C = CString(A.c_str());
			pc.x = C;
		
		}
		 
		
	


	}

	// TODO: 在此添加命令处理程序代码
}


void C作业8练习2View::OnFileSave()
{
	// TODO: 在此添加命令处理程序代码
	C作业8练习2Doc* pDoc = GetDocument();
	CFileDialog cfd(false);  //建立对象
	int r = cfd.DoModal();  //弹出对话框
	CClientDC dc(this);
	if (r == IDOK)                   //如果退出对话框时选项为OK的话

	{
		ofstream ofs(cfd.GetPathName());
		CString s = pDoc->B;
		ofs << CT2A(s.GetString()) << endl;
	}

}


void C作业8练习2View::OnFileSaveAs()
{
	// TODO: 在此添加命令处理程序代码

	CFileDialog cfd(false);  //建立对象
	int r = cfd.DoModal();  //弹出对话框
	CClientDC dc(this);
	if (r == IDOK)                   //如果退出对话框时选项为OK的话

	{
		ofstream ofs(cfd.GetPathName());
		CString s = cfd.GetPathName();
		ofs << CT2A(s.GetString()) << endl;

	}

}


void C作业8练习2View::OnShowpicture()
{
	picture pc;
	int n = pc.DoModal();

	// TODO: 在此添加命令处理程序代码
}
