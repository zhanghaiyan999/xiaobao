
// ����ת��View.cpp : C����ת��View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "����ת��.h"
#endif

#include "����ת��Doc.h"
#include "����ת��View.h"
#include"convert.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C����ת��View

IMPLEMENT_DYNCREATE(C����ת��View, CView)

BEGIN_MESSAGE_MAP(C����ת��View, CView)
END_MESSAGE_MAP()

// C����ת��View ����/����

C����ת��View::C����ת��View()
{
	// TODO: �ڴ˴���ӹ������

}

C����ת��View::~C����ת��View()
{
}

BOOL C����ת��View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C����ת��View ����

void C����ת��View::OnDraw(CDC* pDC)
{
	C����ת��Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	F2 xx;
	CString C;
	C.Format(_T("ת����Ļ���Ϊ��%f"), xx.convert(30.0));
	pDC->TextOutW(200, 200, C);

}


// C����ת��View ���

#ifdef _DEBUG
void C����ת��View::AssertValid() const
{
	CView::AssertValid();
}

void C����ת��View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C����ת��Doc* C����ת��View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C����ת��Doc)));
	return (C����ת��Doc*)m_pDocument;
}
#endif //_DEBUG


// C����ת��View ��Ϣ�������
