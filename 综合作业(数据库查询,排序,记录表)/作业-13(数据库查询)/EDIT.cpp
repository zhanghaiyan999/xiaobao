// EDIT.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "��ҵ-13(���ݿ��ѯ).h"
#include "EDIT.h"
#include "afxdialogex.h"


// EDIT �Ի���

IMPLEMENT_DYNAMIC(EDIT, CDialogEx)

EDIT::EDIT(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG6, pParent)
	, yy(_T(""))
{

}

EDIT::~EDIT()
{
}

void EDIT::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, yy);
}


BEGIN_MESSAGE_MAP(EDIT, CDialogEx)
END_MESSAGE_MAP()


// EDIT ��Ϣ�������
