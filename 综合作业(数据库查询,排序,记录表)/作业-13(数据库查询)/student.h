#pragma once


// student �Ի���

class student : public CDialogEx
{
	DECLARE_DYNAMIC(student)

public:
	student(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~student();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	long id;
	CString name;
	long age;
	long money;
	long phone;
};
