
// 作业-综合实验View.cpp : C作业综合实验View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "作业-综合实验.h"
#endif

#include "作业-综合实验Set.h"
#include "作业-综合实验Doc.h"
#include "作业-综合实验View.h"
#include"bigpicture.h"
#include"order.h"
#include"search.h"
#include"edit.h"
#include "record.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C作业综合实验View

IMPLEMENT_DYNCREATE(C作业综合实验View, CRecordView)

BEGIN_MESSAGE_MAP(C作业综合实验View, CRecordView)
	ON_COMMAND(ID_RECORD_FIRST, &C作业综合实验View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &C作业综合实验View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &C作业综合实验View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &C作业综合实验View::OnRecordLast)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON1, &C作业综合实验View::OnBnClickedButton1)
	ON_COMMAND(ID_SORT, &C作业综合实验View::OnSort)
	ON_COMMAND(ID_add, &C作业综合实验View::Onadd)
	ON_COMMAND(ID_search, &C作业综合实验View::Onsearch)
	ON_COMMAND(ID_delete, &C作业综合实验View::Ondelete)
	ON_COMMAND(ID_edit, &C作业综合实验View::Onedit)
	ON_COMMAND(ID_record, &C作业综合实验View::Onrecord)
	ON_BN_CLICKED(IDC_BUTTON2, &C作业综合实验View::OnBnClickedButton2)
END_MESSAGE_MAP()

// C作业综合实验View 构造/析构

C作业综合实验View::C作业综合实验View()
	: CRecordView(IDD_MY_FORM)
	, id(0)
	, name(_T(""))
	, age(0)
	, money(_T(""))
	, phone(_T(""))
	, picture(_T(""))
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码

}

C作业综合实验View::~C作业综合实验View()
{
}

void C作业综合实验View::DoDataExchange(CDataExchange* pDX)
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
	DDX_Text(pDX, IDC_EDIT6, m_pSet->column5);
	Invalidate();
}

BOOL C作业综合实验View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void C作业综合实验View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_作业综合实验Set;
	CRecordView::OnInitialUpdate();

}


// C作业综合实验View 诊断

#ifdef _DEBUG
void C作业综合实验View::AssertValid() const
{
	CRecordView::AssertValid();
}

void C作业综合实验View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

C作业综合实验Doc* C作业综合实验View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C作业综合实验Doc)));
	return (C作业综合实验Doc*)m_pDocument;
}
#endif //_DEBUG


// C作业综合实验View 数据库支持
CRecordset* C作业综合实验View::OnGetRecordset()
{
	return m_pSet;
}



// C作业综合实验View 消息处理程序


void C作业综合实验View::foo(CImage & img, int & sx, int & sy, int & w, int & h)
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

void C作业综合实验View::OnRecordFirst()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveFirst();
	UpdateData(false);
}


void C作业综合实验View::OnRecordPrev()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
}


void C作业综合实验View::OnRecordNext()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveNext();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
}


void C作业综合实验View::OnRecordLast()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveLast();
	UpdateData(false);
}


void C作业综合实验View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CRecordView::OnPaint()
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


void C作业综合实验View::OnBnClickedButton1()
{
	bigpicture dlg;
	dlg.fil = m_pSet->column5;
	dlg.DoModal();
}


void C作业综合实验View::OnSort()
{
	// TODO: 在此添加命令处理程序代码
	order or ;
	int r = or .DoModal();
	if (r == IDOK)
	{
		m_pSet->m_strSort.Format(_T("%s"), or .x);
		m_pSet->Requery();
		UpdateData(false);


	}
}

void C作业综合实验View::Onadd()
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





	void C作业综合实验View::Onsearch()
	{
		// TODO: 在此添加命令处理程序代码
	}


	void C作业综合实验View::Ondelete()
	{
		// TODO: 在此添加命令处理程序代码
		m_pSet->Delete();
		m_pSet->MovePrev();
		if (m_pSet->IsBOF())
			m_pSet->MoveFirst();
		UpdateData(false);
	}


	void C作业综合实验View::Onedit()
	{
		// TODO: 在此添加命令处理程序代码
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
		void C作业综合实验View::Onrecord()
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


		void C作业综合实验View::OnBnClickedButton2()
		{
			// TODO: 在此添加控件通知处理程序代码

			m_pSet->m_strFilter.Format(_T(""));
			m_pSet->m_strSort.Format(_T(""));
			m_pSet->Requery();
			UpdateData(false);
		}
