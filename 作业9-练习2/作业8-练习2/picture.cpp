// picture.cpp : 实现文件
//

#include "stdafx.h"
#include "作业8-练习2.h"
#include "picture.h"
#include "afxdialogex.h"
#include<fstream>
#include<string>
#include<iostream>
using namespace std;


// picture 对话框

IMPLEMENT_DYNAMIC(picture, CDialogEx)

picture::picture(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

picture::~picture()
{
}

void picture::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(picture, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &picture::OnBnClickedButton1)
END_MESSAGE_MAP()


// picture 消息处理程序


void picture::OnBnClickedButton1()
{
	CString filename;
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	if (r == IDOK)
	{
		filename = cfd.GetPathName();
		ifstream ifs(filename);
		string s;
		ifs >> s;
		CImage img;
		img.Load(CString(s.c_str()));
		int sx, sy, w, h;
		foo(img, sx, sy, w, h);
		CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();
		pDC->SetStretchBltMode(HALFTONE);
		img.Draw(pDC->m_hDC, sx, sy, w, h);
		ReleaseDC(pDC);
	}
	// TODO: 在此添加控件通知处理程序代码
}

void picture::foo(CImage& img, int &sx, int &sy, int &w, int &h)
{
	CRect rect;
	GetDlgItem(IDC_STATIC)->GetClientRect(&rect);
	float rect_ratio = 1.0*rect.Width() / rect.Height();
	float img_ratio = 1.0*img.GetWidth() / img.GetHeight();
	if (rect_ratio> img_ratio)
	{
		h = rect.Height();
		w = img_ratio*h;
		sx = (rect.Width()- w) / 2;
			sy = 0;
		
	}
	else
	{
		w = rect.Width();
		h = w / img_ratio;
		sx = 0;
		sy = (rect.Height() - h) / 2;
	}
}