
// ��ҵ8-1View.cpp : C��ҵ81View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��ҵ8-1.h"
#endif

#include "��ҵ8-1Doc.h"
#include "��ҵ8-1View.h"
#include "Studentlist.h"
#include<fstream>
#include<string>
#include<iostream>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��ҵ81View

IMPLEMENT_DYNCREATE(C��ҵ81View, CView)

BEGIN_MESSAGE_MAP(C��ҵ81View, CView)
	ON_COMMAND(ID_VIEW_STUDENTLIST, &C��ҵ81View::OnViewStudentlist)
END_MESSAGE_MAP()

// C��ҵ81View ����/����

C��ҵ81View::C��ҵ81View()
{
	// TODO: �ڴ˴���ӹ������

}

C��ҵ81View::~C��ҵ81View()
{
}

BOOL C��ҵ81View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C��ҵ81View ����

void C��ҵ81View::OnDraw(CDC* /*pDC*/)
{
	C��ҵ81Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C��ҵ81View ���

#ifdef _DEBUG
void C��ҵ81View::AssertValid() const
{
	CView::AssertValid();
}

void C��ҵ81View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C��ҵ81Doc* C��ҵ81View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C��ҵ81Doc)));
	return (C��ҵ81Doc*)m_pDocument;
}
#endif //_DEBUG


// C��ҵ81View ��Ϣ�������


void C��ҵ81View::OnViewStudentlist()
{
	// TODO: �ڴ���������������
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
