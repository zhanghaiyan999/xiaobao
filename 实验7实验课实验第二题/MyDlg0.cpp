// MyDlg0.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication7(2).h"
#include "MyDlg0.h"
#include "afxdialogex.h"


// MyDlg0 对话框

IMPLEMENT_DYNAMIC(MyDlg0, CDialogEx)

MyDlg0::MyDlg0(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, x(0)
	, y(0)
	, z(0)
{

}

MyDlg0::~MyDlg0()
{
}

void MyDlg0::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, x);
	DDX_Text(pDX, IDC_EDIT2, y);
	DDX_Text(pDX, IDC_EDIT3, z);
}


BEGIN_MESSAGE_MAP(MyDlg0, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &MyDlg0::OnBnClickedButton1)
END_MESSAGE_MAP()


// MyDlg0 消息处理程序


void MyDlg0::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	//MyDlg0 dlg;
	UpdateData(true);
	int a, b, c;
	a = x;
	b = y;
	c = a + b;
	z = c;
	UpdateData(false);
}
