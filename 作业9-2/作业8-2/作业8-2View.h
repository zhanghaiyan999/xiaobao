
// ��ҵ8-2View.h : C��ҵ82View ��Ľӿ�
//

#pragma once


class C��ҵ82View : public CView
{
protected: // �������л�����
	C��ҵ82View();
	DECLARE_DYNCREATE(C��ҵ82View)

// ����
public:
	C��ҵ82Doc* GetDocument() const;

// ����
public:
	int x1;
	int y1;
	int x2;
	int y2;
	CRect A;
	int flag;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~C��ҵ82View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // ��ҵ8-2View.cpp �еĵ��԰汾
inline C��ҵ82Doc* C��ҵ82View::GetDocument() const
   { return reinterpret_cast<C��ҵ82Doc*>(m_pDocument); }
#endif

