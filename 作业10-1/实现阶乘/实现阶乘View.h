
// ʵ�ֽ׳�View.h : Cʵ�ֽ׳�View ��Ľӿ�
//

#pragma once


class Cʵ�ֽ׳�View : public CView
{
protected: // �������л�����
	Cʵ�ֽ׳�View();
	DECLARE_DYNCREATE(Cʵ�ֽ׳�View)

// ����
public:
	Cʵ�ֽ׳�Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~Cʵ�ֽ׳�View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ʵ�ֽ׳�View.cpp �еĵ��԰汾
inline Cʵ�ֽ׳�Doc* Cʵ�ֽ׳�View::GetDocument() const
   { return reinterpret_cast<Cʵ�ֽ׳�Doc*>(m_pDocument); }
#endif

