
// ��ҵ12-(���ݿ����)View.cpp : C��ҵ12���ݿ����View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��ҵ12-(���ݿ����).h"
#endif

#include "��ҵ12-(���ݿ����)Set.h"
#include "��ҵ12-(���ݿ����)Doc.h"
#include "��ҵ12-(���ݿ����)View.h"
#include "ADD.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��ҵ12���ݿ����View

IMPLEMENT_DYNCREATE(C��ҵ12���ݿ����View, CRecordView)

BEGIN_MESSAGE_MAP(C��ҵ12���ݿ����View, CRecordView)
	ON_BN_CLICKED(IDC_BUTTON3, &C��ҵ12���ݿ����View::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &C��ҵ12���ݿ����View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &C��ҵ12���ݿ����View::OnBnClickedButton2)
END_MESSAGE_MAP()

// C��ҵ12���ݿ����View ����/����

C��ҵ12���ݿ����View::C��ҵ12���ݿ����View()
	: CRecordView(IDD_MY12_FORM)
	, z(0)
	, name(_T(""))
	, number(0)
	, age(0)
	, phone(0)
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������

}

C��ҵ12���ݿ����View::~C��ҵ12���ݿ����View()
{
}

void C��ҵ12���ݿ����View::DoDataExchange(CDataExchange* pDX)
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
}

BOOL C��ҵ12���ݿ����View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void C��ҵ12���ݿ����View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_��ҵ12���ݿ����Set;
	CRecordView::OnInitialUpdate();

}


// C��ҵ12���ݿ����View ���

#ifdef _DEBUG
void C��ҵ12���ݿ����View::AssertValid() const
{
	CRecordView::AssertValid();
}

void C��ҵ12���ݿ����View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

C��ҵ12���ݿ����Doc* C��ҵ12���ݿ����View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C��ҵ12���ݿ����Doc)));
	return (C��ҵ12���ݿ����Doc*)m_pDocument;
}
#endif //_DEBUG


// C��ҵ12���ݿ����View ���ݿ�֧��
CRecordset* C��ҵ12���ݿ����View::OnGetRecordset()
{
	return m_pSet;
}



// C��ҵ12���ݿ����View ��Ϣ�������


void C��ҵ12���ݿ����View::OnBnClickedButton3()
{
m_pSet->Delete();
m_pSet->MovePrev();
if (m_pSet->IsBOF())
m_pSet->MoveFirst();
UpdateData(false);

}


void C��ҵ12���ݿ����View::OnBnClickedButton1()
{
	ADD dlg;
	int r=dlg.DoModal();
	if (r==IDOK)
	{     m_pSet->AddNew();
		m_pSet->m_ID = dlg.ID;
		m_pSet->column1 = dlg.name;
		m_pSet->column2 = dlg.number;
		m_pSet->column3 = dlg.age;
		m_pSet->column4 = dlg.phone;
		
		m_pSet->Update();
		UpdateData(false);

	}
}


void C��ҵ12���ݿ����View::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	ADD dlg;
	int r = dlg.DoModal();
	if (r == IDOK)
	{
		m_pSet->Edit();
		m_pSet->m_ID = dlg.ID;
		m_pSet->column1 = dlg.name;
		m_pSet->column2 = dlg.number;
		m_pSet->column3 = dlg.age;
		m_pSet->column4 = dlg.phone;

		m_pSet->Update();
		UpdateData(false);
	}
}
