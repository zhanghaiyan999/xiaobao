// record.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "��ҵ-�ۺ�ʵ��.h"
#include "record.h"
#include "afxdialogex.h"


// record �Ի���

IMPLEMENT_DYNAMIC(record, CDialogEx)

record::record(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG5, pParent)
	, yy(_T(""))
{

}

record::~record()
{
}

void record::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, yy);
}


BEGIN_MESSAGE_MAP(record, CDialogEx)
END_MESSAGE_MAP()


// record ��Ϣ�������
