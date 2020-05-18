
// MFCApplication3(2)View.cpp : CMFCApplication32View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCApplication3(2).h"
#endif

#include "MFCApplication3(2)Doc.h"
#include "MFCApplication3(2)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication32View

IMPLEMENT_DYNCREATE(CMFCApplication32View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication32View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCApplication32View ����/����

CMFCApplication32View::CMFCApplication32View()
{
	// TODO:  �ڴ˴���ӹ������

}

CMFCApplication32View::~CMFCApplication32View()
{
}

BOOL CMFCApplication32View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCApplication32View ����

void CMFCApplication32View::OnDraw(CDC* pDC)
{
	CMFCApplication32Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}

void CMFCApplication32View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCApplication32View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCApplication32View ���

#ifdef _DEBUG
void CMFCApplication32View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication32View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication32Doc* CMFCApplication32View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication32Doc)));
	return (CMFCApplication32Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication32View ��Ϣ�������


void CMFCApplication32View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFCApplication32Doc* pDoc = GetDocument();
	CString s;
	s.Format(_T("A+B= %d"), pDoc->A + pDoc->B );
	CClientDC dc(this);
	dc.TextOutW(200, 200, s);
	CView::OnLButtonDown(nFlags, point);
}
