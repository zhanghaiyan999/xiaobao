
// Using��ϰ9View.cpp : CUsing��ϰ9View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Using��ϰ9.h"
#endif

#include "Using��ϰ9Doc.h"
#include "Using��ϰ9View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include"w32.h"
#include"Win32D.h"

// CUsing��ϰ9View

IMPLEMENT_DYNCREATE(CUsing��ϰ9View, CView)

BEGIN_MESSAGE_MAP(CUsing��ϰ9View, CView)
END_MESSAGE_MAP()

// CUsing��ϰ9View ����/����

CUsing��ϰ9View::CUsing��ϰ9View()
{
	// TODO: �ڴ˴���ӹ������

}

CUsing��ϰ9View::~CUsing��ϰ9View()
{
}

BOOL CUsing��ϰ9View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CUsing��ϰ9View ����

void CUsing��ϰ9View::OnDraw(CDC* pDC)
{
	CUsing��ϰ9Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)

		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CString S;
	S = CString(pchar());
	pDC->TextOutW(200, 300, S);
	CString C;
	C.Format(_T("%d"), )
	CString A;
	A.Format(_T("%d,���ǴӶ�̬���ӿ�ȡ�õķ���ֵ"), GetInt());
	pDC->TextOutW(200, 200, A);
}


// CUsing��ϰ9View ���

#ifdef _DEBUG
void CUsing��ϰ9View::AssertValid() const
{
	CView::AssertValid();
}

void CUsing��ϰ9View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CUsing��ϰ9Doc* CUsing��ϰ9View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CUsing��ϰ9Doc)));
	return (CUsing��ϰ9Doc*)m_pDocument;
}
#endif //_DEBUG


// CUsing��ϰ9View ��Ϣ�������
