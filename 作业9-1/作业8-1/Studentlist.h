#pragma once
#include "afxwin.h"


// Studentlist �Ի���

class Studentlist : public CDialogEx
{
	DECLARE_DYNAMIC(Studentlist)

public:
	Studentlist(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Studentlist();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif
	CString S;
	int n;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListBox list;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	CString X;
	afx_msg void OnBnClickedButton2();
};
