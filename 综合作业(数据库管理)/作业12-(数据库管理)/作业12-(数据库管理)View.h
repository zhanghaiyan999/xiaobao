
// ��ҵ12-(���ݿ����)View.h : C��ҵ12���ݿ����View ��Ľӿ�
//

#pragma once

class C��ҵ12���ݿ����Set;

class C��ҵ12���ݿ����View : public CRecordView
{
protected: // �������л�����
	C��ҵ12���ݿ����View();
	DECLARE_DYNCREATE(C��ҵ12���ݿ����View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MY12_FORM };
#endif
	C��ҵ12���ݿ����Set* m_pSet;

// ����
public:
	C��ҵ12���ݿ����Doc* GetDocument() const;

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
	virtual ~C��ҵ12���ݿ����View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	long z;
	CString name;
	LONGLONG number;
	long age;
	long phone;
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};

#ifndef _DEBUG  // ��ҵ12-(���ݿ����)View.cpp �еĵ��԰汾
inline C��ҵ12���ݿ����Doc* C��ҵ12���ݿ����View::GetDocument() const
   { return reinterpret_cast<C��ҵ12���ݿ����Doc*>(m_pDocument); }
#endif

