#pragma once


// bigpicture �Ի���

class bigpicture : public CDialogEx
{
	DECLARE_DYNAMIC(bigpicture)

public:
	bigpicture(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~bigpicture();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	void foo(CString filename);
	DECLARE_MESSAGE_MAP()
public:
	CString fil;
	afx_msg void OnPaint();
};
