#pragma once


// record �Ի���

class record : public CDialogEx
{
	DECLARE_DYNAMIC(record)

public:
	record(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~record();
	CString yy;

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG5 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
