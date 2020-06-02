﻿
// shiyan2(3)View.h: Cshiyan23View 类的接口
//

#pragma once


class Cshiyan23View : public CView
{
protected: // 仅从序列化创建
	Cshiyan23View() noexcept;
	DECLARE_DYNCREATE(Cshiyan23View)

// 特性
public:
	Cshiyan23Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Cshiyan23View();
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
};

#ifndef _DEBUG  // shiyan2(3)View.cpp 中的调试版本
inline Cshiyan23Doc* Cshiyan23View::GetDocument() const
   { return reinterpret_cast<Cshiyan23Doc*>(m_pDocument); }
#endif

