
// ��ҵ8-1View.h : C��ҵ81View ��Ľӿ�
//

#pragma once


class C��ҵ81View : public CView
{
protected: // �������л�����
	C��ҵ81View();
	DECLARE_DYNCREATE(C��ҵ81View)

// ����
public:
	C��ҵ81Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~C��ҵ81View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnViewStudentlist();
};

#ifndef _DEBUG  // ��ҵ8-1View.cpp �еĵ��԰汾
inline C��ҵ81Doc* C��ҵ81View::GetDocument() const
   { return reinterpret_cast<C��ҵ81Doc*>(m_pDocument); }
#endif

