
// ��ҵ11-2(�Ի���ͼƬ)Dlg.h : ͷ�ļ�
//

#pragma once


// C��ҵ112�Ի���ͼƬDlg �Ի���
class C��ҵ112�Ի���ͼƬDlg : public CDialogEx
{
// ����
public:
	C��ҵ112�Ի���ͼƬDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY112_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	void foo(CString filename);
};
