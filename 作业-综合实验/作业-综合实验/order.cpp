// order.cpp : 实现文件
//

#include "stdafx.h"
#include "作业-综合实验.h"
#include "order.h"
#include "afxdialogex.h"


// order 对话框

IMPLEMENT_DYNAMIC(order, CDialogEx)

order::order(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

order::~order()
{
}

void order::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(order, CDialogEx)
END_MESSAGE_MAP()


// order 消息处理程序
