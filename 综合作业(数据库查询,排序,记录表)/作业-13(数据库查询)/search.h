#pragma once


// search �Ի���

class search : public CDialogEx
{
	DECLARE_DYNAMIC(search)

public:
	search(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~search();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString y;
};
