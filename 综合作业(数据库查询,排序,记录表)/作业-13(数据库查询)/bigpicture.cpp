// bigpicture.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "��ҵ-13(���ݿ��ѯ).h"
#include "bigpicture.h"
#include "afxdialogex.h"


// bigpicture �Ի���

IMPLEMENT_DYNAMIC(bigpicture, CDialogEx)

bigpicture::bigpicture(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

bigpicture::~bigpicture()
{
}

void bigpicture::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

void bigpicture::foo(CString filename)
{
	CImage img;
	img.Load(filename);
	int sx, sy, w, h;
	CRect rect;
	CDC *pDC = GetDlgItem(IDC_STATIC1)->GetDC();
	GetDlgItem(IDC_STATIC1)->GetClientRect(&rect);
	float rect_ratio = 1.0*rect.Width() / rect.Height();
	float img_ratio = 1.0*img.GetWidth() / img.GetHeight();
	if (rect_ratio> img_ratio)
	{
		h = rect.Height();
		w = img_ratio*h;
		sx = (rect.Width() - w) / 2;
		sy = 0;

	}
	else
	{
		w = rect.Width();
		h = w / img_ratio;
		sx = 0;
		sy = (rect.Height() - h) / 2;
	}
	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);

}


BEGIN_MESSAGE_MAP(bigpicture, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// bigpicture ��Ϣ�������


void bigpicture::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: �ڴ˴������Ϣ����������
					   // ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
	foo(fil);
}
