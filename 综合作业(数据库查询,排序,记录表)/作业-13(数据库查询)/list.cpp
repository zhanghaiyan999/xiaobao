// list.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "��ҵ-13(���ݿ��ѯ).h"
#include "list.h"
#include "afxdialogex.h"


// list �Ի���

IMPLEMENT_DYNAMIC(list, CDialogEx)

list::list(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG5, pParent)

	, xx(_T(""))
{

}

list::~list()
{
}

void list::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_LBString(pDX, IDC_EDIT1, xx);
	DDX_Text(pDX, IDC_EDIT1, xx);
}


BEGIN_MESSAGE_MAP(list, CDialogEx)
END_MESSAGE_MAP()


// list ��Ϣ�������
