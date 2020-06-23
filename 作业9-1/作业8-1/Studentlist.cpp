// Studentlist.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "��ҵ8-1.h"
#include "Studentlist.h"
#include "afxdialogex.h"
#include<fstream>
#include<string>
#include<iostream>
using namespace std;


// Studentlist �Ի���

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


// Studentlist ��Ϣ�������


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
	
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void Studentlist::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	 n = list.GetCurSel();
	list.GetText(n, S);
     X = S;
	 UpdateData(false);

}


void Studentlist::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	this->UpdateData(true);
	S = X;
	list.DeleteString(n);
	list.InsertString(n, S);



}
