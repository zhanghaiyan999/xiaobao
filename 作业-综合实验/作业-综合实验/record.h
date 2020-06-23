#pragma once


// record 对话框

class record : public CDialogEx
{
	DECLARE_DYNAMIC(record)

public:
	record(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~record();
	CString yy;

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG5 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
