
// ��ҵ10-3View.h : C��ҵ103View ��Ľӿ�
//

#pragma once

class C��ҵ103Set;

class C��ҵ103View : public CRecordView
{
protected: // �������л�����
	C��ҵ103View();
	DECLARE_DYNCREATE(C��ҵ103View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MY103_FORM };
#endif
	C��ҵ103Set* m_pSet;

// ����
public:
	C��ҵ103Doc* GetDocument() const;

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
	virtual ~C��ҵ103View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	CString iD;
	CString NAME;
	afx_msg void OnEnChangeEdit3();
	long number;
	long age;
	long phone;
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
	void C��ҵ103View::foo(CImage&img, int&sx, int&sy, int&w, int&h);
	afx_msg void OnPaint();
};

#ifndef _DEBUG  // ��ҵ10-3View.cpp �еĵ��԰汾
inline C��ҵ103Doc* C��ҵ103View::GetDocument() const
   { return reinterpret_cast<C��ҵ103Doc*>(m_pDocument); }
#endif

