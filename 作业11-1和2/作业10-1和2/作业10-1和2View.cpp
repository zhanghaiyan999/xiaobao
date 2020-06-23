
// 作业10-1和2View.cpp : C作业101和2View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "作业10-1和2.h"
#endif

#include "作业10-1和2Set.h"
#include "作业10-1和2Doc.h"
#include "作业10-1和2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C作业101和2View

IMPLEMENT_DYNCREATE(C作业101和2View, CRecordView)

BEGIN_MESSAGE_MAP(C作业101和2View, CRecordView)
	ON_EN_CHANGE(IDC_EDIT2, &C作业101和2View::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT1, &C作业101和2View::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, &C作业101和2View::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT3, &C作业101和2View::OnEnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT5, &C作业101和2View::OnEnChangeEdit5)
END_MESSAGE_MAP()

// C作业101和2View 构造/析构

C作业101和2View::C作业101和2View()
	: CRecordView(IDD_MY1012_FORM)
	, ID(0)
	, name(_T(""))
	, number(_T(""))
	, age(_T(""))
	, phone(_T(""))
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码

}

C作业101和2View::~C作业101和2View()
{
}

void C作业101和2View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1,m_pSet->m_ID);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->column1);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->column2);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->column3);
	DDX_Text(pDX, IDC_EDIT5, m_pSet->column4);
	Invalidate();
}

BOOL C作业101和2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void C作业101和2View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_作业101和2Set;
	CRecordView::OnInitialUpdate();

}


// C作业101和2View 诊断

#ifdef _DEBUG
void C作业101和2View::AssertValid() const
{
	CRecordView::AssertValid();
}

void C作业101和2View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

C作业101和2Doc* C作业101和2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C作业101和2Doc)));
	return (C作业101和2Doc*)m_pDocument;
}
#endif //_DEBUG


// C作业101和2View 数据库支持
CRecordset* C作业101和2View::OnGetRecordset()
{
	return m_pSet;
}



// C作业101和2View 消息处理程序


void C作业101和2View::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CRecordView::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void C作业101和2View::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CRecordView::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void C作业101和2View::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	
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


void C作业101和2View::OnEnChangeEdit3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CRecordView::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

/*void C作业101和2View::foo(CImage & img, int & sx, int & sy, int & w, int & h)
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



void C作业101和2View::OnEnChangeEdit5()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CRecordView::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
