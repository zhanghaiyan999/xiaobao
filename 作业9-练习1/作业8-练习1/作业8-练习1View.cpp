
// ��ҵ8-��ϰ1View.cpp : C��ҵ8��ϰ1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��ҵ8-��ϰ1.h"
#endif

#include "��ҵ8-��ϰ1Doc.h"
#include "��ҵ8-��ϰ1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��ҵ8��ϰ1View

IMPLEMENT_DYNCREATE(C��ҵ8��ϰ1View, CView)

BEGIN_MESSAGE_MAP(C��ҵ8��ϰ1View, CView)
	ON_COMMAND(ID_CFILEDIALOG, &C��ҵ8��ϰ1View::OnCfiledialog)
	ON_COMMAND(ID_FILE_OPEN, &C��ҵ8��ϰ1View::OnFileOpen)
END_MESSAGE_MAP()

// C��ҵ8��ϰ1View ����/����

C��ҵ8��ϰ1View::C��ҵ8��ϰ1View()
{
	// TODO: �ڴ˴���ӹ������

}

C��ҵ8��ϰ1View::~C��ҵ8��ϰ1View()
{
}

BOOL C��ҵ8��ϰ1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C��ҵ8��ϰ1View ����

void C��ҵ8��ϰ1View::OnDraw(CDC* /*pDC*/)
{
	C��ҵ8��ϰ1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C��ҵ8��ϰ1View ���

#ifdef _DEBUG
void C��ҵ8��ϰ1View::AssertValid() const
{
	CView::AssertValid();
}

void C��ҵ8��ϰ1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C��ҵ8��ϰ1Doc* C��ҵ8��ϰ1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C��ҵ8��ϰ1Doc)));
	return (C��ҵ8��ϰ1Doc*)m_pDocument;
}
#endif //_DEBUG


// C��ҵ8��ϰ1View ��Ϣ�������


void C��ҵ8��ϰ1View::OnCfiledialog()
{
	// TODO: �ڴ���������������
	C��ҵ8��ϰ1Doc* pDoc = GetDocument();
	CFileDialog cfd(true);  //��������
	int r = cfd.DoModal();  //�����Ի���
	CClientDC dc(this);
	if (r == IDOK)                   //����˳��Ի���ʱѡ��ΪOK�Ļ�

	{
		CString filename = cfd.GetPathName();

		dc.TextOutW(300, 200, filename);
		pDoc->A = filename;


	}

}


void C��ҵ8��ϰ1View::OnFileOpen()
{
	// TODO: �ڴ���������������
	C��ҵ8��ϰ1Doc* pDoc = GetDocument();
	CFileDialog cfd(true);  //��������
	int r = cfd.DoModal();  //�����Ի���
	CClientDC dc(this);
	if (r == IDOK)                   //����˳��Ի���ʱѡ��ΪOK�Ļ�

	{
		CString filename = cfd.GetPathName();

		dc.TextOutW(300, 200, filename);
		pDoc->A = filename;


	}

}
