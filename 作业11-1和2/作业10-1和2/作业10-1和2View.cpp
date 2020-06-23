
// ��ҵ10-1��2View.cpp : C��ҵ101��2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��ҵ10-1��2.h"
#endif

#include "��ҵ10-1��2Set.h"
#include "��ҵ10-1��2Doc.h"
#include "��ҵ10-1��2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��ҵ101��2View

IMPLEMENT_DYNCREATE(C��ҵ101��2View, CRecordView)

BEGIN_MESSAGE_MAP(C��ҵ101��2View, CRecordView)
	ON_EN_CHANGE(IDC_EDIT2, &C��ҵ101��2View::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT1, &C��ҵ101��2View::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, &C��ҵ101��2View::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT3, &C��ҵ101��2View::OnEnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT5, &C��ҵ101��2View::OnEnChangeEdit5)
END_MESSAGE_MAP()

// C��ҵ101��2View ����/����

C��ҵ101��2View::C��ҵ101��2View()
	: CRecordView(IDD_MY1012_FORM)
	, ID(0)
	, name(_T(""))
	, number(_T(""))
	, age(_T(""))
	, phone(_T(""))
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������

}

C��ҵ101��2View::~C��ҵ101��2View()
{
}

void C��ҵ101��2View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1,m_pSet->m_ID);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->column1);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->column2);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->column3);
	DDX_Text(pDX, IDC_EDIT5, m_pSet->column4);
	Invalidate();
}

BOOL C��ҵ101��2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void C��ҵ101��2View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_��ҵ101��2Set;
	CRecordView::OnInitialUpdate();

}


// C��ҵ101��2View ���

#ifdef _DEBUG
void C��ҵ101��2View::AssertValid() const
{
	CRecordView::AssertValid();
}

void C��ҵ101��2View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

C��ҵ101��2Doc* C��ҵ101��2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C��ҵ101��2Doc)));
	return (C��ҵ101��2Doc*)m_pDocument;
}
#endif //_DEBUG


// C��ҵ101��2View ���ݿ�֧��
CRecordset* C��ҵ101��2View::OnGetRecordset()
{
	return m_pSet;
}



// C��ҵ101��2View ��Ϣ�������


void C��ҵ101��2View::OnEnChangeEdit2()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CRecordView::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void C��ҵ101��2View::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CRecordView::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void C��ҵ101��2View::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
	CImage img;
	CString s;
	m_pSet->GetFieldValue(short(5), s);
	img.Load(s);	
	CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();
	int sx, sy, w, h;
	CRect rect;
	GetDlgItem(IDC_STATIC)->GetClientRect(&rect);
	float rect_ratio = 1.0*rect.Width() / rect.Height();
	float img_ratio = 1.0*img.GetWidth() / img.GetHeight();
	if (rect_ratio> img_ratio)
	{
		h = rect.Height();
		w = img_ratio*h;
		sx = (rect.Width() - w) / 2;
		sy = 0;

	}
	else
	{
		w = rect.Width();
		h = w / img_ratio;
		sx = 0;
		sy = (rect.Height() - h) / 2;
	}

	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);






}


void C��ҵ101��2View::OnEnChangeEdit3()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CRecordView::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}

/*void C��ҵ101��2View::foo(CImage & img, int & sx, int & sy, int & w, int & h)
{
	CRect rect;
	GetDlgItem(IDC_STATIC)->GetClientRect(&rect);
	float rect_ratio = 1.0*rect.Width() / rect.Height();
	float img_ratio = 1.0*img.GetWidth() / img.GetHeight();
	if (rect_ratio> img_ratio)
	{
		h = rect.Height();
		w = img_ratio*h;
		sx = (rect.Width() - w) / 2;
		sy = 0;

	}
	else
	{
		w = rect.Width();
		h = w / img_ratio;
		sx = 0;
		sy = (rect.Height() - h) / 2;
	}
}*/



void C��ҵ101��2View::OnEnChangeEdit5()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CRecordView::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
