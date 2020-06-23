
// ��ҵ8-2View.cpp : C��ҵ82View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��ҵ8-2.h"
#endif

#include "��ҵ8-2Doc.h"
#include "��ҵ8-2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��ҵ82View

IMPLEMENT_DYNCREATE(C��ҵ82View, CView)

BEGIN_MESSAGE_MAP(C��ҵ82View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// C��ҵ82View ����/����

C��ҵ82View::C��ҵ82View()
{
	// TODO: �ڴ˴���ӹ������


}

C��ҵ82View::~C��ҵ82View()
{
}

BOOL C��ҵ82View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C��ҵ82View ����

void C��ҵ82View::OnDraw(CDC* pDC)
{
	C��ҵ82Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
for (int i = 0; i <pDoc->ca.GetSize(); i++)
		pDC->Ellipse(pDoc->ca.GetAt(i));
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C��ҵ82View ���

#ifdef _DEBUG
void C��ҵ82View::AssertValid() const
{
	CView::AssertValid();
}

void C��ҵ82View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C��ҵ82Doc* C��ҵ82View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C��ҵ82Doc)));
	return (C��ҵ82Doc*)m_pDocument;
}
#endif //_DEBUG


// C��ҵ82View ��Ϣ�������


void C��ҵ82View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	x1 = point.x;
	y1 = point.y;
	flag = 1;
	CView::OnLButtonDown(nFlags, point);
}


void C��ҵ82View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	C��ҵ82Doc* pDoc = GetDocument();
	CClientDC dc(this);
	x2 = point.x;
	y2 = point.y;
	A.left = x1;
	A.top = y1;
	A.right = x2;
	A.bottom = y2;
	Invalidate();
	flag = 0;
	pDoc->ca.Add(A);
	Invalidate();
	CView::OnLButtonUp(nFlags, point);
}


void C��ҵ82View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (flag == 1)
	{
		CClientDC dc(this);
		x2 = point.x;
		y2 = point.y;
		A.left = x1;
		A.top = y1;
		A.right = x2;
		A.bottom = y2;
		dc.Ellipse(A);
		Invalidate();
	}
	CView::OnMouseMove(nFlags, point);
}
