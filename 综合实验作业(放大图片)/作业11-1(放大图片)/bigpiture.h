#pragma once


// bigpiture �Ի���

class bigpiture : public CDialogEx
{
	DECLARE_DYNAMIC(bigpiture)

public:
	bigpiture(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~bigpiture();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString fil;
	
	void foo(CString filename);
	afx_msg void OnPaint();
};
