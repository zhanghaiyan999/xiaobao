
// ����ת��View.h : C����ת��View ��Ľӿ�
//

#pragma once


class C����ת��View : public CView
{
protected: // �������л�����
	C����ת��View();
	DECLARE_DYNCREATE(C����ת��View)

// ����
public:
	C����ת��Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~C����ת��View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ����ת��View.cpp �еĵ��԰汾
inline C����ת��Doc* C����ת��View::GetDocument() const
   { return reinterpret_cast<C����ת��Doc*>(m_pDocument); }
#endif

