
// 作业10-练习View.cpp : C作业10练习View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "作业10-练习.h"
#endif

#include "作业10-练习Set.h"
#include "作业10-练习Doc.h"
#include "作业10-练习View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C作业10练习View

IMPLEMENT_DYNCREATE(C作业10练习View, CRecordView)

BEGIN_MESSAGE_MAP(C作业10练习View, CRecordView)
	ON_EN_CHANGE(IDC_EDIT3, &C作业10练习View::OnEnChangeEdit3)
END_MESSAGE_MAP()

// C作业10练习View 构造/析构

C作业10练习View::C作业10练习View()
	: CRecordView(IDD_MY10_FORM)
	, ID(0)
	, NAME(_T(""))
	, NUMBER(_T(""))
	, AGE(_T(""))
	, PHONE(_T(""))
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码

}

C作业10练习View::~C作业10练习View()
{
}

void C作业10练习View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_ID);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->column1);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->column2);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->column3);
	DDX_Text(pDX, IDC_EDIT5, m_pSet->column4);
}

BOOL C作业10练习View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void C作业10练习View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_作业10练习Set;
	CRecordView::OnInitialUpdate();

}


// C作业10练习View 诊断

#ifdef _DEBUG
void C作业10练习View::AssertValid() const
{
	CRecordView::AssertValid();
}

void C作业10练习View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

C作业10练习Doc* C作业10练习View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C作业10练习Doc)));
	return (C作业10练习Doc*)m_pDocument;
}
#endif //_DEBUG


// C作业10练习View 数据库支持
CRecordset* C作业10练习View::OnGetRecordset()
{
	return m_pSet;
}



// C作业10练习View 消息处理程序


void C作业10练习View::OnEnChangeEdit3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CRecordView::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
