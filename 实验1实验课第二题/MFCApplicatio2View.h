﻿
// MFCApplicatio2View.h: CMFCApplicatio2View 类的接口
//

#pragma once


class CMFCApplicatio2View : public CView
{
protected: // 仅从序列化创建
	CMFCApplicatio2View() noexcept;
	DECLARE_DYNCREATE(CMFCApplicatio2View)

// 特性
public:
	CMFCApplicatio2Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCApplicatio2View();
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
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFCApplicatio2View.cpp 中的调试版本
inline CMFCApplicatio2Doc* CMFCApplicatio2View::GetDocument() const
   { return reinterpret_cast<CMFCApplicatio2Doc*>(m_pDocument); }
#endif

