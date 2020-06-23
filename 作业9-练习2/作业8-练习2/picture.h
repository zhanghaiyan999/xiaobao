#pragma once


// picture 对话框

class picture : public CDialogEx
{
	DECLARE_DYNAMIC(picture)

public:
	picture(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~picture();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif


	CString x;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	void foo(CImage& img, int &sx, int &sy, int &w, int &h);
};
