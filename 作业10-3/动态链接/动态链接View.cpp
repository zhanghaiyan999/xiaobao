
// ��̬����View.cpp : C��̬����View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��̬����.h"
#endif

#include "��̬����Doc.h"
#include "��̬����View.h"
#include"��ҵ9-3.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��̬����View

IMPLEMENT_DYNCREATE(C��̬����View, CView)

BEGIN_MESSAGE_MAP(C��̬����View, CView)
END_MESSAGE_MAP()

// C��̬����View ����/����

C��̬����View::C��̬����View()
{
	// TODO: �ڴ˴���ӹ������

}

C��̬����View::~C��̬����View()
{
}

BOOL C��̬����View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C��̬����View ����

void C��̬����View::OnDraw(CDC* pDC)
{
	C��̬����Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CString X, XX, XXX;
	X.Format(_T("%d���������ʹ��"), GetNum(pDoc->n));
	if (Factorial(pDoc->n) > 2147483647)
	{
		XX.Format(_T("�����Ľ׳������"));
	}
	else
	{
XX.Format(_T("�����Ľ׳�Ϊ��%d"), Factorial(pDoc->n));
	}

	XXX.Format(_T("�����Ļ���Ϊ��%f"), convert(30.0));
	pDC->TextOutW(200, 200, X);
	pDC->TextOutW(200, 250, XX);
	pDC->TextOutW(200, 300, XXX);


}


// C��̬����View ���

#ifdef _DEBUG
void C��̬����View::AssertValid() const
{
	CView::AssertValid();
}

void C��̬����View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C��̬����Doc* C��̬����View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C��̬����Doc)));
	return (C��̬����Doc*)m_pDocument;
}
#endif //_DEBUG


// C��̬����View ��Ϣ�������
