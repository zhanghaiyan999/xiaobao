// edit.cpp : 实现文件
//

#include "stdafx.h"
#include "作业-综合实验.h"
#include "edit.h"
#include "afxdialogex.h"


// edit 对话框

IMPLEMENT_DYNAMIC(edit, CDialogEx)

edit::edit(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG4, pParent)
	, id(0)
	, name(_T(""))
	, age(0)
	,money(0)
	, phone(0)
	, picture(_T(""))
{

}

edit::~edit()
{
}

void edit::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, id);
	DDX_Text(pDX, IDC_EDIT2, name);
	DDX_Text(pDX, IDC_EDIT3, age);
	DDX_Text(pDX, IDC_EDIT4, money);
	DDX_Text(pDX, IDC_EDIT5, phone);
	DDX_Text(pDX, IDC_EDIT6, picture);
}


BEGIN_MESSAGE_MAP(edit, CDialogEx)
END_MESSAGE_MAP()


// edit 消息处理程序
