#pragma once


// list �Ի���

class list : public CDialogEx
{
	DECLARE_DYNAMIC(list)

public:
	list(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~list();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG5 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:

	CString xx;
};
