#pragma once


// EDIT �Ի���

class EDIT : public CDialogEx
{
	DECLARE_DYNAMIC(EDIT)

public:
	EDIT(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~EDIT();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG6 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString yy;
};
