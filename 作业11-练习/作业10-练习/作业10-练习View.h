
// ��ҵ10-��ϰView.h : C��ҵ10��ϰView ��Ľӿ�
//

#pragma once

class C��ҵ10��ϰSet;

class C��ҵ10��ϰView : public CRecordView
{
protected: // �������л�����
	C��ҵ10��ϰView();
	DECLARE_DYNCREATE(C��ҵ10��ϰView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MY10_FORM };
#endif
	C��ҵ10��ϰSet* m_pSet;

// ����
public:
	C��ҵ10��ϰDoc* GetDocument() const;

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
	virtual ~C��ҵ10��ϰView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	long ID;
	CString NAME;
	CString NUMBER;
	CString AGE;
	CString PHONE;
	afx_msg void OnEnChangeEdit3();
};

#ifndef _DEBUG  // ��ҵ10-��ϰView.cpp �еĵ��԰汾
inline C��ҵ10��ϰDoc* C��ҵ10��ϰView::GetDocument() const
   { return reinterpret_cast<C��ҵ10��ϰDoc*>(m_pDocument); }
#endif

