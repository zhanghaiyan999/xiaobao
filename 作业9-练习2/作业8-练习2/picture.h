#pragma once


// picture �Ի���

class picture : public CDialogEx
{
	DECLARE_DYNAMIC(picture)

public:
	picture(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~picture();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif


	CString x;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	void foo(CImage& img, int &sx, int &sy, int &w, int &h);
};
