
// ��ҵ10-1��2View.h : C��ҵ101��2View ��Ľӿ�
//

#pragma once

class C��ҵ101��2Set;

class C��ҵ101��2View : public CRecordView
{
protected: // �������л�����
	C��ҵ101��2View();
	DECLARE_DYNCREATE(C��ҵ101��2View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MY1012_FORM };
#endif
	C��ҵ101��2Set* m_pSet;

// ����
public:
	C��ҵ101��2Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~C��ҵ101��2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnChangeEdit1();
	long ID;
	CString name;
	CString number;
	CString age;
	CString phone;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeEdit3();
	void foo(CImage& img, int &sx, int &sy, int &w, int &h);
	afx_msg void OnEnChangeEdit5();
};

#ifndef _DEBUG  // ��ҵ10-1��2View.cpp �еĵ��԰汾
inline C��ҵ101��2Doc* C��ҵ101��2View::GetDocument() const
   { return reinterpret_cast<C��ҵ101��2Doc*>(m_pDocument); }
#endif

