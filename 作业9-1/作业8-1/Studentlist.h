#pragma once
#include "afxwin.h"


// Studentlist 对话框

class Studentlist : public CDialogEx
{
	DECLARE_DYNAMIC(Studentlist)

public:
	Studentlist(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Studentlist();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif
	CString S;
	int n;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListBox list;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	CString X;
	afx_msg void OnBnClickedButton2();
};
