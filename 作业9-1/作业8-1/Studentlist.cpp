// Studentlist.cpp : 实现文件
//

#include "stdafx.h"
#include "作业8-1.h"
#include "Studentlist.h"
#include "afxdialogex.h"
#include<fstream>
#include<string>
#include<iostream>
using namespace std;


// Studentlist 对话框

IMPLEMENT_DYNAMIC(Studentlist, CDialogEx)

Studentlist::Studentlist(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, X(_T(""))
{

}

Studentlist::~Studentlist()
{
}

void Studentlist::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, list);
	DDX_Text(pDX, IDC_EDIT1, X);
}


BEGIN_MESSAGE_MAP(Studentlist, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Studentlist::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Studentlist::OnBnClickedButton2)
END_MESSAGE_MAP()


// Studentlist 消息处理程序


BOOL Studentlist::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CFileDialog cfd(true);
	int r = cfd.DoModal();
	if (r == IDOK)
	{
		CString filename = cfd.GetPathName();
		ifstream ifs(filename);
		string s;
		CClientDC dc(this);
		while (ifs>>s)
		{
			CString z = CString(s.c_str());
			list.AddString(z);

		}


	}
	
	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void Studentlist::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	 n = list.GetCurSel();
	list.GetText(n, S);
     X = S;
	 UpdateData(false);

}


void Studentlist::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	this->UpdateData(true);
	S = X;
	list.DeleteString(n);
	list.InsertString(n, S);



}
