#pragma once


// order �Ի���

class order : public CDialogEx
{
	DECLARE_DYNAMIC(order)

public:
	order(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~order();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString x;
};
