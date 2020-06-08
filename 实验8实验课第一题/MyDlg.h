#pragma once


// MyDlg 对话框

class MyDlg : public CDialogEx
{
	DECLARE_DYNAMIC(MyDlg)

public:
	MyDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~MyDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString s;
	//输入的2个值
	double m1;
	double m2;
	//保存计算符号0=‘+’，1=‘-’2=‘*’，3=‘/‘，6=’指数‘
	int m;
	//计算
	void SaveValuel();
	void Calculator();
	//运算符号
	//CALCULATOR_FLAG mflag;

	afx_msg void OnBnClickedButtonabout();
	afx_msg void OnBnClickedButtonback();
	afx_msg void OnBnClickedButtonclear();
	afx_msg void OnBnClickedButtonjia();
	afx_msg void OnBnClickedButtonjian();
	afx_msg void OnBnClickedButtoncheng();
	afx_msg void OnBnClickedButtonchu();
	afx_msg void OnBnClickedButtonkaifang();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton0();
	afx_msg void OnBnClickedButtondian();
	afx_msg void OnBnClickedButtonpingfang();
	afx_msg void OnBnClickedButtondeng();
};
