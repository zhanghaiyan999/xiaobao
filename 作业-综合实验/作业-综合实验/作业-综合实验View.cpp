
// ��ҵ-�ۺ�ʵ��View.cpp : C��ҵ�ۺ�ʵ��View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��ҵ-�ۺ�ʵ��.h"
#endif

#include "��ҵ-�ۺ�ʵ��Set.h"
#include "��ҵ-�ۺ�ʵ��Doc.h"
#include "��ҵ-�ۺ�ʵ��View.h"
#include"bigpicture.h"
#include"order.h"
#include"search.h"
#include"edit.h"
#include "record.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��ҵ�ۺ�ʵ��View

IMPLEMENT_DYNCREATE(C��ҵ�ۺ�ʵ��View, CRecordView)

BEGIN_MESSAGE_MAP(C��ҵ�ۺ�ʵ��View, CRecordView)
	ON_COMMAND(ID_RECORD_FIRST, &C��ҵ�ۺ�ʵ��View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &C��ҵ�ۺ�ʵ��View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &C��ҵ�ۺ�ʵ��View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &C��ҵ�ۺ�ʵ��View::OnRecordLast)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON1, &C��ҵ�ۺ�ʵ��View::OnBnClickedButton1)
	ON_COMMAND(ID_SORT, &C��ҵ�ۺ�ʵ��View::OnSort)
	ON_COMMAND(ID_add, &C��ҵ�ۺ�ʵ��View::Onadd)
	ON_COMMAND(ID_search, &C��ҵ�ۺ�ʵ��View::Onsearch)
	ON_COMMAND(ID_delete, &C��ҵ�ۺ�ʵ��View::Ondelete)
	ON_COMMAND(ID_edit, &C��ҵ�ۺ�ʵ��View::Onedit)
	ON_COMMAND(ID_record, &C��ҵ�ۺ�ʵ��View::Onrecord)
	ON_BN_CLICKED(IDC_BUTTON2, &C��ҵ�ۺ�ʵ��View::OnBnClickedButton2)
END_MESSAGE_MAP()

// C��ҵ�ۺ�ʵ��View ����/����

C��ҵ�ۺ�ʵ��View::C��ҵ�ۺ�ʵ��View()
	: CRecordView(IDD_MY_FORM)
	, id(0)
	, name(_T(""))
	, age(0)
	, money(_T(""))
	, phone(_T(""))
	, picture(_T(""))
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������

}

C��ҵ�ۺ�ʵ��View::~C��ҵ�ۺ�ʵ��View()
{
}

void C��ҵ�ۺ�ʵ��View::DoDataExchange(CDataExchange* pDX)
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
	DDX_Text(pDX, IDC_EDIT6, m_pSet->column5);
	Invalidate();
}

BOOL C��ҵ�ۺ�ʵ��View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void C��ҵ�ۺ�ʵ��View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_��ҵ�ۺ�ʵ��Set;
	CRecordView::OnInitialUpdate();

}


// C��ҵ�ۺ�ʵ��View ���

#ifdef _DEBUG
void C��ҵ�ۺ�ʵ��View::AssertValid() const
{
	CRecordView::AssertValid();
}

void C��ҵ�ۺ�ʵ��View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

C��ҵ�ۺ�ʵ��Doc* C��ҵ�ۺ�ʵ��View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C��ҵ�ۺ�ʵ��Doc)));
	return (C��ҵ�ۺ�ʵ��Doc*)m_pDocument;
}
#endif //_DEBUG


// C��ҵ�ۺ�ʵ��View ���ݿ�֧��
CRecordset* C��ҵ�ۺ�ʵ��View::OnGetRecordset()
{
	return m_pSet;
}



// C��ҵ�ۺ�ʵ��View ��Ϣ�������


void C��ҵ�ۺ�ʵ��View::foo(CImage & img, int & sx, int & sy, int & w, int & h)
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

void C��ҵ�ۺ�ʵ��View::OnRecordFirst()
{
	// TODO: �ڴ���������������
	m_pSet->MoveFirst();
	UpdateData(false);
}


void C��ҵ�ۺ�ʵ��View::OnRecordPrev()
{
	// TODO: �ڴ���������������
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
}


void C��ҵ�ۺ�ʵ��View::OnRecordNext()
{
	// TODO: �ڴ���������������
	m_pSet->MoveNext();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
}


void C��ҵ�ۺ�ʵ��View::OnRecordLast()
{
	// TODO: �ڴ���������������
	m_pSet->MoveLast();
	UpdateData(false);
}


void C��ҵ�ۺ�ʵ��View::OnPaint()
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


void C��ҵ�ۺ�ʵ��View::OnBnClickedButton1()
{
	bigpicture dlg;
	dlg.fil = m_pSet->column5;
	dlg.DoModal();
}


void C��ҵ�ۺ�ʵ��View::OnSort()
{
	// TODO: �ڴ���������������
	order or ;
	int r = or .DoModal();
	if (r == IDOK)
	{
		m_pSet->m_strSort.Format(_T("%s"), or .x);
		m_pSet->Requery();
		UpdateData(false);


	}
}

void C��ҵ�ۺ�ʵ��View::Onadd()
{
	edit stu;
	int r = stu.DoModal();
	if (r == IDOK)
	{
		m_pSet->AddNew();
		m_pSet->m_ID = stu.id;
		m_pSet->column1 = stu.name;
		m_pSet->column2 = stu.age;
		m_pSet->column3 = stu.money;
		m_pSet->column4 = stu.phone;
		m_pSet->column5 = stu.picture;
		m_pSet->Update();
		UpdateData(false);


	}
}





	void C��ҵ�ۺ�ʵ��View::Onsearch()
	{
		// TODO: �ڴ���������������
	}


	void C��ҵ�ۺ�ʵ��View::Ondelete()
	{
		// TODO: �ڴ���������������
		m_pSet->Delete();
		m_pSet->MovePrev();
		if (m_pSet->IsBOF())
			m_pSet->MoveFirst();
		UpdateData(false);
	}


	void C��ҵ�ۺ�ʵ��View::Onedit()
	{
		// TODO: �ڴ���������������
		edit stu;
		int r = stu.DoModal();
		if (r == IDOK)
		{
			m_pSet->AddNew();
			m_pSet->m_ID = stu.id;
			m_pSet->column1 = stu.name;
			m_pSet->column2 = stu.age;
			m_pSet->column3 = stu.money;
			m_pSet->column4 = stu.phone;
			m_pSet->column5 = stu.picture;

			m_pSet->Update();
			UpdateData(false);
		}

	}
		void C��ҵ�ۺ�ʵ��View::Onrecord()
		{
			record dlg;
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


		void C��ҵ�ۺ�ʵ��View::OnBnClickedButton2()
		{
			// TODO: �ڴ���ӿؼ�֪ͨ����������

			m_pSet->m_strFilter.Format(_T(""));
			m_pSet->m_strSort.Format(_T(""));
			m_pSet->Requery();
			UpdateData(false);
		}
