
// ��ҵ10-��ϰView.cpp : C��ҵ10��ϰView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��ҵ10-��ϰ.h"
#endif

#include "��ҵ10-��ϰSet.h"
#include "��ҵ10-��ϰDoc.h"
#include "��ҵ10-��ϰView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��ҵ10��ϰView

IMPLEMENT_DYNCREATE(C��ҵ10��ϰView, CRecordView)

BEGIN_MESSAGE_MAP(C��ҵ10��ϰView, CRecordView)
	ON_EN_CHANGE(IDC_EDIT3, &C��ҵ10��ϰView::OnEnChangeEdit3)
END_MESSAGE_MAP()

// C��ҵ10��ϰView ����/����

C��ҵ10��ϰView::C��ҵ10��ϰView()
	: CRecordView(IDD_MY10_FORM)
	, ID(0)
	, NAME(_T(""))
	, NUMBER(_T(""))
	, AGE(_T(""))
	, PHONE(_T(""))
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������

}

C��ҵ10��ϰView::~C��ҵ10��ϰView()
{
}

void C��ҵ10��ϰView::DoDataExchange(CDataExchange* pDX)
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

BOOL C��ҵ10��ϰView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void C��ҵ10��ϰView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_��ҵ10��ϰSet;
	CRecordView::OnInitialUpdate();

}


// C��ҵ10��ϰView ���

#ifdef _DEBUG
void C��ҵ10��ϰView::AssertValid() const
{
	CRecordView::AssertValid();
}

void C��ҵ10��ϰView::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

C��ҵ10��ϰDoc* C��ҵ10��ϰView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C��ҵ10��ϰDoc)));
	return (C��ҵ10��ϰDoc*)m_pDocument;
}
#endif //_DEBUG


// C��ҵ10��ϰView ���ݿ�֧��
CRecordset* C��ҵ10��ϰView::OnGetRecordset()
{
	return m_pSet;
}



// C��ҵ10��ϰView ��Ϣ�������


void C��ҵ10��ϰView::OnEnChangeEdit3()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CRecordView::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
