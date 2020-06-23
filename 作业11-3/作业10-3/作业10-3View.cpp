
// ��ҵ10-3View.cpp : C��ҵ103View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��ҵ10-3.h"
#endif

#include "��ҵ10-3Set.h"
#include "��ҵ10-3Doc.h"
#include "��ҵ10-3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��ҵ103View

IMPLEMENT_DYNCREATE(C��ҵ103View, CRecordView)

BEGIN_MESSAGE_MAP(C��ҵ103View, CRecordView)
	ON_EN_CHANGE(IDC_EDIT1, &C��ҵ103View::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT3, &C��ҵ103View::OnEnChangeEdit3)
	ON_COMMAND(ID_RECORD_FIRST, &C��ҵ103View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &C��ҵ103View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &C��ҵ103View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &C��ҵ103View::OnRecordLast)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// C��ҵ103View ����/����

C��ҵ103View::C��ҵ103View()
	: CRecordView(IDD_MY103_FORM)
	, iD(_T(""))
	, NAME(_T(""))
	, number(0)
	, age(0)
	, phone(0)
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������

}

C��ҵ103View::~C��ҵ103View()
{
}

void C��ҵ103View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_ID);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->column1);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->column2);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->column3);
	DDX_Text(pDX, IDC_EDIT5, m_pSet->column4);
	Invalidate();
}

BOOL C��ҵ103View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void C��ҵ103View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_��ҵ103Set;
	CRecordView::OnInitialUpdate();

}


// C��ҵ103View ���

#ifdef _DEBUG
void C��ҵ103View::AssertValid() const
{
	CRecordView::AssertValid();
}

void C��ҵ103View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

C��ҵ103Doc* C��ҵ103View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C��ҵ103Doc)));
	return (C��ҵ103Doc*)m_pDocument;
}
#endif //_DEBUG


// C��ҵ103View ���ݿ�֧��
CRecordset* C��ҵ103View::OnGetRecordset()
{
	return m_pSet;
}



// C��ҵ103View ��Ϣ�������


void C��ҵ103View::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CRecordView::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void C��ҵ103View::OnEnChangeEdit3()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CRecordView::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}






void C��ҵ103View::OnRecordFirst()
{
	// TODO: �ڴ���������������
	m_pSet->MoveFirst();
	UpdateData(false);
}


void C��ҵ103View::OnRecordPrev()
{
	// TODO: �ڴ���������������
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);

}


void C��ҵ103View::OnRecordNext()
{
	m_pSet->MoveNext();
	if(m_pSet->IsBOF())
	m_pSet->MoveFirst();
	UpdateData(false);
	// TODO: �ڴ���������������
}


void C��ҵ103View::OnRecordLast()
{
	// TODO: �ڴ���������������
	m_pSet->MoveLast();
	UpdateData(false);
}


void C��ҵ103View::foo(CImage&img, int&sx, int&sy, int&w, int&h)
{
	CRect rect;
	GetDlgItem(IDC_STATIC)->GetClientRect(&rect);
	float rect_ratio = 1.0*rect.Width() / rect.Height();
	float img_ratio = 1.0*img.GetWidth() / img.GetHeight();

	if (rect_ratio > img_ratio)
	{
		h = rect.Height();
		w = img_ratio*h;
		sx = (rect.Width() - w) / 2;
		sy = 0;
	}
	else {
		w = rect.Width();
		h = w / img_ratio;
		sy = (rect.Height() - h) / 2;
		sx = 0;
	}
}


void C��ҵ103View::OnPaint()
{
	
	CPaintDC dc(this); 
	CString S = m_pSet->column5;
	CImage img;
	img.Load(S);
	CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();
	int sx, sy, w, h;
	foo(img, sx, sy, w, h);
	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);
	

}
