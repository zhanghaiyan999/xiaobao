// ADD.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "��ҵ12-(���ݿ����).h"
#include "ADD.h"
#include "afxdialogex.h"


// ADD �Ի���

IMPLEMENT_DYNAMIC(ADD, CDialogEx)

ADD::ADD(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ADD, pParent)
	, ID(0)
	, name(_T(""))
	, number(0)
	, age(0)
	, phone(0)
{

}

ADD::~ADD()
{
}

void ADD::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, ID);
	DDX_Text(pDX, IDC_EDIT2, name);
	DDX_Text(pDX, IDC_EDIT3, number);
	DDX_Text(pDX, IDC_EDIT4, age);
	DDX_Text(pDX, IDC_EDIT5, phone);
}


BEGIN_MESSAGE_MAP(ADD, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &ADD::OnEnChangeEdit1)
END_MESSAGE_MAP()


// ADD ��Ϣ�������


void ADD::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
