
// ��ҵ-�ۺ�ʵ��View.h : C��ҵ�ۺ�ʵ��View ��Ľӿ�
//

#pragma once

class C��ҵ�ۺ�ʵ��Set;

class C��ҵ�ۺ�ʵ��View : public CRecordView
{
protected: // �������л�����
	C��ҵ�ۺ�ʵ��View();
	DECLARE_DYNCREATE(C��ҵ�ۺ�ʵ��View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MY_FORM };
#endif
	C��ҵ�ۺ�ʵ��Set* m_pSet;

// ����
public:
	C��ҵ�ۺ�ʵ��Doc* GetDocument() const;

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
	virtual ~C��ҵ�ۺ�ʵ��View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	long id;
	CString name;
	long age;
	CString money;
	CString phone;
	CString picture;
	afx_msg
		void foo(CImage & img, int & sx, int & sy, int & w, int & h);
	void OnRecordFirst();
	void OnRecordPrev();
	void OnRecordNext();
	void OnRecordLast();
	void OnPaint();
	void OnBnClickedButton1();
	afx_msg void OnSort();
	afx_msg void Onadd();
	afx_msg void Onsearch();
	afx_msg void Ondelete();
	afx_msg void Onedit();
	afx_msg void Onrecord();
	afx_msg void OnBnClickedButton2();
};

#ifndef _DEBUG  // ��ҵ-�ۺ�ʵ��View.cpp �еĵ��԰汾
inline C��ҵ�ۺ�ʵ��Doc* C��ҵ�ۺ�ʵ��View::GetDocument() const
   { return reinterpret_cast<C��ҵ�ۺ�ʵ��Doc*>(m_pDocument); }
#endif

