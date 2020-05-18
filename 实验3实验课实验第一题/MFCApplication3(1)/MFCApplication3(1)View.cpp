
// MFCApplication3(1)View.cpp : CMFCApplication31View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCApplication3(1).h"
#endif

#include "MFCApplication3(1)Doc.h"
#include "MFCApplication3(1)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication31View

IMPLEMENT_DYNCREATE(CMFCApplication31View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication31View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMFCApplication31View ����/����

CMFCApplication31View::CMFCApplication31View()
{
	// TODO:  �ڴ˴���ӹ������

}

CMFCApplication31View::~CMFCApplication31View()
{
}

BOOL CMFCApplication31View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCApplication31View ����

void CMFCApplication31View::OnDraw(CDC* /*pDC*/)
{
	CMFCApplication31Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}

void CMFCApplication31View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCApplication31View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCApplication31View ���

#ifdef _DEBUG
void CMFCApplication31View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication31View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication31Doc* CMFCApplication31View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication31Doc)));
	return (CMFCApplication31Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication31View ��Ϣ�������


void CMFCApplication31View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CString s;
	s.Format(_T("������ڱ�����"));
	CClientDC dc(this);
	dc.TextOutW(200, 200, s);


	CView::OnLButtonDown(nFlags, point);
}


void CMFCApplication31View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CString s;
	s.Format(_T("������ڱ�̧��"));
	CClientDC dc(this);
	dc.TextOutW(200, 200, s);

	CView::OnLButtonUp(nFlags, point);
}
