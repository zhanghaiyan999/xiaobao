
// ��ҵ8-��ϰ2View.cpp : C��ҵ8��ϰ2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��ҵ8-��ϰ2.h"
#endif

#include "��ҵ8-��ϰ2Doc.h"
#include "��ҵ8-��ϰ2View.h"
#include "picture.h"
#include<fstream>
#include<string>
#include<iostream>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��ҵ8��ϰ2View

IMPLEMENT_DYNCREATE(C��ҵ8��ϰ2View, CView)

BEGIN_MESSAGE_MAP(C��ҵ8��ϰ2View, CView)
	ON_COMMAND(ID_FILE_OPEN, &C��ҵ8��ϰ2View::OnFileOpen)
	ON_COMMAND(ID_FILE_SAVE, &C��ҵ8��ϰ2View::OnFileSave)
	ON_COMMAND(ID_FILE_SAVE_AS, &C��ҵ8��ϰ2View::OnFileSaveAs)
	ON_COMMAND(ID_SHOWPICTURE, &C��ҵ8��ϰ2View::OnShowpicture)
END_MESSAGE_MAP()

// C��ҵ8��ϰ2View ����/����

C��ҵ8��ϰ2View::C��ҵ8��ϰ2View()
{
	// TODO: �ڴ˴���ӹ������

}

C��ҵ8��ϰ2View::~C��ҵ8��ϰ2View()
{
}

BOOL C��ҵ8��ϰ2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C��ҵ8��ϰ2View ����

void C��ҵ8��ϰ2View::OnDraw(CDC* /*pDC*/)
{
	C��ҵ8��ϰ2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C��ҵ8��ϰ2View ���

#ifdef _DEBUG
void C��ҵ8��ϰ2View::AssertValid() const
{
	CView::AssertValid();
}

void C��ҵ8��ϰ2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C��ҵ8��ϰ2Doc* C��ҵ8��ϰ2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C��ҵ8��ϰ2Doc)));
	return (C��ҵ8��ϰ2Doc*)m_pDocument;
}
#endif //_DEBUG


// C��ҵ8��ϰ2View ��Ϣ�������


void C��ҵ8��ϰ2View::OnFileOpen()
{
	C��ҵ8��ϰ2Doc* pDoc = GetDocument();
	picture pc;

	CFileDialog cfd(true);  //��������
	int r = cfd.DoModal();  //�����Ի���
	CClientDC dc(this);
	if (r == IDOK)                   //����˳��Ի���ʱѡ��ΪOK�Ļ�

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

	// TODO: �ڴ���������������
}


void C��ҵ8��ϰ2View::OnFileSave()
{
	// TODO: �ڴ���������������
	C��ҵ8��ϰ2Doc* pDoc = GetDocument();
	CFileDialog cfd(false);  //��������
	int r = cfd.DoModal();  //�����Ի���
	CClientDC dc(this);
	if (r == IDOK)                   //����˳��Ի���ʱѡ��ΪOK�Ļ�

	{
		ofstream ofs(cfd.GetPathName());
		CString s = pDoc->B;
		ofs << CT2A(s.GetString()) << endl;
	}

}


void C��ҵ8��ϰ2View::OnFileSaveAs()
{
	// TODO: �ڴ���������������

	CFileDialog cfd(false);  //��������
	int r = cfd.DoModal();  //�����Ի���
	CClientDC dc(this);
	if (r == IDOK)                   //����˳��Ի���ʱѡ��ΪOK�Ļ�

	{
		ofstream ofs(cfd.GetPathName());
		CString s = cfd.GetPathName();
		ofs << CT2A(s.GetString()) << endl;

	}

}


void C��ҵ8��ϰ2View::OnShowpicture()
{
	picture pc;
	int n = pc.DoModal();

	// TODO: �ڴ���������������
}
