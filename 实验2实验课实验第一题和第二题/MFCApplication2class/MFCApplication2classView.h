
// MFCApplication2classView.h : CMFCApplication2classView ��Ľӿ�
//

#pragma once


class CMFCApplication2classView : public CView
{
protected: // �������л�����
	CMFCApplication2classView();
	DECLARE_DYNCREATE(CMFCApplication2classView)

// ����
public:
	CMFCApplication2classDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFCApplication2classView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFCApplication2classView.cpp �еĵ��԰汾
inline CMFCApplication2classDoc* CMFCApplication2classView::GetDocument() const
   { return reinterpret_cast<CMFCApplication2classDoc*>(m_pDocument); }
#endif

