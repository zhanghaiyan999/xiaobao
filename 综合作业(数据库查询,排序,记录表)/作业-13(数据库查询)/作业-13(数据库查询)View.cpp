
// ��ҵ-13(���ݿ��ѯ)View.cpp : C��ҵ13���ݿ��ѯView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��ҵ-13(���ݿ��ѯ).h"
#endif

#include "��ҵ-13(���ݿ��ѯ)Set.h"
#include "��ҵ-13(���ݿ��ѯ)Doc.h"
#include "��ҵ-13(���ݿ��ѯ)View.h"
#include "bigpicture.h"
#include"order.h"
#include"search.h"
#include"student.h"
#include"EDIT.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��ҵ13���ݿ��ѯView

IMPLEMENT_DYNCREATE(C��ҵ13���ݿ��ѯView, CRecordView)

BEGIN_MESSAGE_MAP(C��ҵ13���ݿ��ѯView, CRecordView)
	ON_BN_CLICKED(IDC_BUTTON2, &C��ҵ13���ݿ��ѯView::OnBnClickedButton2)
	ON_WM_PAINT()
	ON_COMMAND(ID_RECORD_FIRST, &C��ҵ13���ݿ��ѯView::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &C��ҵ13���ݿ��ѯView::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &C��ҵ13���ݿ��ѯView::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &C��ҵ13���ݿ��ѯView::OnRecordLast)
	ON_BN_CLICKED(IDC_BUTTON1, &C��ҵ13���ݿ��ѯView::OnBnClickedButton1)
	ON_COMMAND(ID_paixu, &C��ҵ13���ݿ��ѯView::Onpaixu)
	ON_COMMAND(ID_search, &C��ҵ13���ݿ��ѯView::Onsearch)
	ON_COMMAND(ID_ADD, &C��ҵ13���ݿ��ѯView::OnAdd)
	ON_COMMAND(ID_DELETE, &C��ҵ13���ݿ��ѯView::OnDelete)
	ON_COMMAND(ID_EDIT, &C��ҵ13���ݿ��ѯView::OnEdit)
	ON_COMMAND(ID_RECORD, &C��ҵ13���ݿ��ѯView::OnRecord)
END_MESSAGE_MAP()

// C��ҵ13���ݿ��ѯView ����/����

C��ҵ13���ݿ��ѯView::C��ҵ13���ݿ��ѯView()
	: CRecordView(IDD_MY13_FORM)
	, id(0)
	, name(_T(""))
	, age(0)
	, money(0)
	, phone(0)
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������

}

C��ҵ13���ݿ��ѯView::~C��ҵ13���ݿ��ѯView()
{
}

void C��ҵ13���ݿ��ѯView::DoDataExchange(CDataExchange* pDX)
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

BOOL C��ҵ13���ݿ��ѯView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void C��ҵ13���ݿ��ѯView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_��ҵ13���ݿ��ѯSet;
	CRecordView::OnInitialUpdate();

}


// C��ҵ13���ݿ��ѯView ���

#ifdef _DEBUG
void C��ҵ13���ݿ��ѯView::AssertValid() const
{
	CRecordView::AssertValid();
}

void C��ҵ13���ݿ��ѯView::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

C��ҵ13���ݿ��ѯDoc* C��ҵ13���ݿ��ѯView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C��ҵ13���ݿ��ѯDoc)));
	return (C��ҵ13���ݿ��ѯDoc*)m_pDocument;
}
#endif //_DEBUG


// C��ҵ13���ݿ��ѯView ���ݿ�֧��
CRecordset* C��ҵ13���ݿ��ѯView::OnGetRecordset()
{
	return m_pSet;
}



// C��ҵ13���ݿ��ѯView ��Ϣ�������


void C��ҵ13���ݿ��ѯView::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_pSet->m_strFilter.Format(_T(""));
	m_pSet->m_strSort.Format(_T(""));
	m_pSet->Requery();
	UpdateData(false);



}

void C��ҵ13���ݿ��ѯView::foo(CImage & img, int & sx, int & sy, int & w, int & h)
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


void C��ҵ13���ݿ��ѯView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: �ڴ˴������Ϣ����������
					   // ��Ϊ��ͼ��Ϣ���� CRecordView::OnPaint()
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


void C��ҵ13���ݿ��ѯView::OnRecordFirst()
{
	// TODO: �ڴ���������������
	m_pSet->MoveFirst();
	UpdateData(false);
}


void C��ҵ13���ݿ��ѯView::OnRecordPrev()
{
	// TODO: �ڴ���������������
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);	
}


void C��ҵ13���ݿ��ѯView::OnRecordNext()
{
	// TODO: �ڴ���������������
	m_pSet->MoveNext();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
}


void C��ҵ13���ݿ��ѯView::OnRecordLast()
{
	// TODO: �ڴ���������������
	m_pSet->MoveLast();
	UpdateData(false);
}



void C��ҵ13���ݿ��ѯView::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	bigpicture dlg;
	dlg.fil = m_pSet->column5;
	dlg.DoModal();
}


void C��ҵ13���ݿ��ѯView::Onpaixu()
{
	// TODO: �ڴ���������������
	order or ;
	int r=or .DoModal();
	if (r == IDOK)
	{
		m_pSet->m_strSort.Format(_T("%s"), or.x);
		m_pSet->Requery();
		UpdateData(false);


	}
}


void C��ҵ13���ݿ��ѯView::Onsearch()
{
	// TODO: �ڴ���������������
	search sea;
	int r = sea.DoModal();
	if (r == IDOK)
	{
		m_pSet->m_strFilter = sea.y;
		m_pSet->Requery();
		UpdateData(false);

	}
}


void C��ҵ13���ݿ��ѯView::OnAdd()
{
	student stu;
	int r = stu.DoModal();
	if (r == IDOK)
	{
		m_pSet->AddNew();
		m_pSet->m_ID = stu.id;
		m_pSet->column1 = stu.name;
		m_pSet->column2 = stu.age;
		m_pSet->column3 = stu.money;
		m_pSet->column4 = stu.phone;

		m_pSet->Update();
		UpdateData(false);


	}
}


void C��ҵ13���ݿ��ѯView::OnDelete()
{
	// TODO: �ڴ���������������
	m_pSet->Delete();
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
}



void C��ҵ13���ݿ��ѯView::OnEdit()
{
	// TODO: �ڴ���������������
	student stu;
	int r = stu.DoModal();
	if (r == IDOK)
	{
		m_pSet->AddNew();
		m_pSet->m_ID = stu.id;
		m_pSet->column1 = stu.name;
		m_pSet->column2 = stu.age;
		m_pSet->column3 = stu.money;
		m_pSet->column4 = stu.phone;

		m_pSet->Update();
		UpdateData(false);


	}

}


void C��ҵ13���ݿ��ѯView::OnRecord()
{
	// TODO: �ڴ���������������
	EDIT dlg;
	int n, i;
	CString str, s;

	m_pSet->MoveFirst();
	while (!m_pSet->IsEOF())

	{
		n = m_pSet->GetODBCFieldCount();


		for (i = 1; i < n; i++)
		{
			m_pSet->GetFieldValue((short)i, str);
			s += _T(" ") + str;
		}
		s += _T("\r\n");
		dlg.yy = s;
		UpdateData(false);
		m_pSet->MoveNext();
	}
	if (dlg.DoModal() == IDOK)
	{

	}

	

}
