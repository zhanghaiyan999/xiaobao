
// ��ҵ11-1(�Ŵ�ͼƬ)View.cpp : C��ҵ111�Ŵ�ͼƬView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��ҵ11-1(�Ŵ�ͼƬ).h"
#endif

#include "��ҵ11-1(�Ŵ�ͼƬ)Set.h"
#include "��ҵ11-1(�Ŵ�ͼƬ)Doc.h"
#include "��ҵ11-1(�Ŵ�ͼƬ)View.h"
#include "bigpiture.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��ҵ111�Ŵ�ͼƬView

IMPLEMENT_DYNCREATE(C��ҵ111�Ŵ�ͼƬView, CRecordView)

BEGIN_MESSAGE_MAP(C��ҵ111�Ŵ�ͼƬView, CRecordView)
	ON_EN_CHANGE(IDC_EDIT5, &C��ҵ111�Ŵ�ͼƬView::OnEnChangeEdit5)
	ON_EN_CHANGE(IDC_EDIT3, &C��ҵ111�Ŵ�ͼƬView::OnEnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT4, &C��ҵ111�Ŵ�ͼƬView::OnEnChangeEdit4)
	ON_COMMAND(ID_RECORD_FIRST, &C��ҵ111�Ŵ�ͼƬView::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &C��ҵ111�Ŵ�ͼƬView::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &C��ҵ111�Ŵ�ͼƬView::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &C��ҵ111�Ŵ�ͼƬView::OnRecordLast)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON1, &C��ҵ111�Ŵ�ͼƬView::OnBnClickedButton1)
END_MESSAGE_MAP()

// C��ҵ111�Ŵ�ͼƬView ����/����

C��ҵ111�Ŵ�ͼƬView::C��ҵ111�Ŵ�ͼƬView()
	: CRecordView(IDD_MY111_FORM)
	, id(0)
	, name(_T(""))
	, number(0)
	, age(0)
	, phone(0)
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������

}

C��ҵ111�Ŵ�ͼƬView::~C��ҵ111�Ŵ�ͼƬView()
{
}

void C��ҵ111�Ŵ�ͼƬView::DoDataExchange(CDataExchange* pDX)
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

BOOL C��ҵ111�Ŵ�ͼƬView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void C��ҵ111�Ŵ�ͼƬView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_��ҵ111�Ŵ�ͼƬSet;
	CRecordView::OnInitialUpdate();

}


// C��ҵ111�Ŵ�ͼƬView ���

#ifdef _DEBUG
void C��ҵ111�Ŵ�ͼƬView::AssertValid() const
{
	CRecordView::AssertValid();
}

void C��ҵ111�Ŵ�ͼƬView::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

C��ҵ111�Ŵ�ͼƬDoc* C��ҵ111�Ŵ�ͼƬView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C��ҵ111�Ŵ�ͼƬDoc)));
	return (C��ҵ111�Ŵ�ͼƬDoc*)m_pDocument;
}
#endif //_DEBUG


// C��ҵ111�Ŵ�ͼƬView ���ݿ�֧��
CRecordset* C��ҵ111�Ŵ�ͼƬView::OnGetRecordset()
{
	return m_pSet;
}



// C��ҵ111�Ŵ�ͼƬView ��Ϣ�������

void C��ҵ111�Ŵ�ͼƬView::OnEnChangeEdit5()

{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CRecordView::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void C��ҵ111�Ŵ�ͼƬView::OnEnChangeEdit3()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CRecordView::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void C��ҵ111�Ŵ�ͼƬView::OnEnChangeEdit4()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CRecordView::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void C��ҵ111�Ŵ�ͼƬView::OnRecordFirst()
{
	// TODO: �ڴ���������������
	m_pSet->MoveFirst();
	UpdateData(false);
}


void C��ҵ111�Ŵ�ͼƬView::OnRecordPrev()
{
	// TODO: �ڴ���������������
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
}


void C��ҵ111�Ŵ�ͼƬView::OnRecordNext()
{
	// TODO: �ڴ���������������
	m_pSet->MoveNext();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
}


void C��ҵ111�Ŵ�ͼƬView::OnRecordLast()
{
	// TODO: �ڴ���������������
	m_pSet->MoveLast();
	UpdateData(false);

}

void C��ҵ111�Ŵ�ͼƬView::foo(CImage & img, int & sx, int & sy, int & w, int & h)
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






void C��ҵ111�Ŵ�ͼƬView::OnPaint()
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


void C��ҵ111�Ŵ�ͼƬView::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	bigpiture xx;
	xx.fil = m_pSet->column5;
	xx.DoModal();
	
}
