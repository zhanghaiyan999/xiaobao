
// MFCApplication4(3)View.h: CMFCApplication43View 类的接口
//

#pragma once


class CMFCApplication43View : public CView
{
protected: // 仅从序列化创建
	CMFCApplication43View() noexcept;
	DECLARE_DYNCREATE(CMFCApplication43View)

// 特性
public:
	CMFCApplication43Doc* GetDocument() const;

// 操作
public:
	CArray<CRect, CRect&>cr;
	bool set;
	int N;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCApplication43View();
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
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // MFCApplication4(3)View.cpp 中的调试版本
inline CMFCApplication43Doc* CMFCApplication43View::GetDocument() const
   { return reinterpret_cast<CMFCApplication43Doc*>(m_pDocument); }
#endif

