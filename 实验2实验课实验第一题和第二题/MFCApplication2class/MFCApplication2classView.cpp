
// MFCApplication2classView.cpp : CMFCApplication2classView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCApplication2class.h"
#endif

#include "MFCApplication2classDoc.h"
#include "MFCApplication2classView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication2classView

IMPLEMENT_DYNCREATE(CMFCApplication2classView, CView)

BEGIN_MESSAGE_MAP(CMFCApplication2classView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMFCApplication2classView ����/����

CMFCApplication2classView::CMFCApplication2classView()
{
	// TODO:  �ڴ˴���ӹ������

}

CMFCApplication2classView::~CMFCApplication2classView()
{
}

BOOL CMFCApplication2classView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCApplication2classView ����

void CMFCApplication2classView::OnDraw(CDC* pDC)
{
	CMFCApplication2classDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���

	pDoc->b.Format(_T("%d"),pDoc->A);
	pDC->TextOutW(200, 200, pDoc->s);
	pDC->TextOutW(300, 300, pDoc->b);
	                                                                                                                                                                                                                                                                                                                                                                                                                                      

}

void CMFCApplication2classView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCApplication2classView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCApplication2classView ���

#ifdef _DEBUG
void CMFCApplication2classView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication2classView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication2classDoc* CMFCApplication2classView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication2classDoc)));
	return (CMFCApplication2classDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication2classView ��Ϣ�������
