// order.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "��ҵ-13(���ݿ��ѯ).h"
#include "order.h"
#include "afxdialogex.h"


// order �Ի���

IMPLEMENT_DYNAMIC(order, CDialogEx)

order::order(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, x(_T(""))
{

}

order::~order()
{
}

void order::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, x);
}


BEGIN_MESSAGE_MAP(order, CDialogEx)
END_MESSAGE_MAP()


// order ��Ϣ�������
