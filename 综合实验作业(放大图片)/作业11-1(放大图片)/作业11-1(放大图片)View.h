
// ��ҵ11-1(�Ŵ�ͼƬ)View.h : C��ҵ111�Ŵ�ͼƬView ��Ľӿ�
//

#pragma once

class C��ҵ111�Ŵ�ͼƬSet;

class C��ҵ111�Ŵ�ͼƬView : public CRecordView
{
protected: // �������л�����
	C��ҵ111�Ŵ�ͼƬView();
	DECLARE_DYNCREATE(C��ҵ111�Ŵ�ͼƬView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MY111_FORM };
#endif
	C��ҵ111�Ŵ�ͼƬSet* m_pSet;

// ����
public:
	C��ҵ111�Ŵ�ͼƬDoc* GetDocument() const;

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
	virtual ~C��ҵ111�Ŵ�ͼƬView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit5();
	afx_msg void OnEnChangeEdit3();
	long id;
	CString name;
	long number;
	long age;
	long phone;
	afx_msg void OnEnChangeEdit4();
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
	void foo(CImage & img, int & sx, int & sy, int & w, int & h);

	afx_msg void OnPaint();
	afx_msg void OnBnClickedButton1();
};

#ifndef _DEBUG  // ��ҵ11-1(�Ŵ�ͼƬ)View.cpp �еĵ��԰汾
inline C��ҵ111�Ŵ�ͼƬDoc* C��ҵ111�Ŵ�ͼƬView::GetDocument() const
   { return reinterpret_cast<C��ҵ111�Ŵ�ͼƬDoc*>(m_pDocument); }
#endif

