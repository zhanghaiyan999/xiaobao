
// ��ҵ-13(���ݿ��ѯ)View.h : C��ҵ13���ݿ��ѯView ��Ľӿ�
//

#pragma once

class C��ҵ13���ݿ��ѯSet;

class C��ҵ13���ݿ��ѯView : public CRecordView
{
protected: // �������л�����
	C��ҵ13���ݿ��ѯView();
	DECLARE_DYNCREATE(C��ҵ13���ݿ��ѯView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MY13_FORM };
#endif
	C��ҵ13���ݿ��ѯSet* m_pSet;

// ����
public:
	C��ҵ13���ݿ��ѯDoc* GetDocument() const;

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
	virtual ~C��ҵ13���ݿ��ѯView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
	long id;
	CString name;
	long age;
	long money;
	long phone;
	void foo(CImage & img, int & sx, int & sy, int & w, int & h);
	afx_msg void OnPaint();
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
	afx_msg void OnBnClickedButton1();
	afx_msg void Onpaixu();
	afx_msg void Onsearch();
	afx_msg void OnAdd();
	afx_msg void OnDelete();
	afx_msg void OnEdit();
	afx_msg void OnRecord();
};

#ifndef _DEBUG  // ��ҵ-13(���ݿ��ѯ)View.cpp �еĵ��԰汾
inline C��ҵ13���ݿ��ѯDoc* C��ҵ13���ݿ��ѯView::GetDocument() const
   { return reinterpret_cast<C��ҵ13���ݿ��ѯDoc*>(m_pDocument); }
#endif

