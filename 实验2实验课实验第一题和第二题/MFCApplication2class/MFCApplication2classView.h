
// MFCApplication2classView.h : CMFCApplication2classView 类的接口
//

#pragma once


class CMFCApplication2classView : public CView
{
protected: // 仅从序列化创建
	CMFCApplication2classView();
	DECLARE_DYNCREATE(CMFCApplication2classView)

// 特性
public:
	CMFCApplication2classDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCApplication2classView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFCApplication2classView.cpp 中的调试版本
inline CMFCApplication2classDoc* CMFCApplication2classView::GetDocument() const
   { return reinterpret_cast<CMFCApplication2classDoc*>(m_pDocument); }
#endif

