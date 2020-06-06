// MyDlg.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication8.h"
#include "MyDlg.h"
#include "afxdialogex.h"


// MyDlg 对话框

IMPLEMENT_DYNAMIC(MyDlg, CDialogEx)

MyDlg::MyDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

MyDlg::~MyDlg()
{
}

void MyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, Lbox);
}


BEGIN_MESSAGE_MAP(MyDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &MyDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// MyDlg 消息处理程序


BOOL MyDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	// 设置过滤器
	TCHAR szFilter[] = _T("文本文件(.txt)|.txt|所有文件(.)|.||");
	// 构造打开文件对话框
	CFileDialog fileDlg(TRUE, _T("txt"), NULL, 0, szFilter, this);
	if (IDOK == fileDlg.DoModal())
	{

		// 如果点击了文件对话框上的“打开”按钮，则将选择的文件路径显示到编辑框里
		strFilePath = fileDlg.GetPathName();
		Lbox.AddString(strFilePath);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void MyDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码、
	int n = Lbox.GetCurSel();//取得当前所选记录号

	Lbox.GetText(n, s);

}
