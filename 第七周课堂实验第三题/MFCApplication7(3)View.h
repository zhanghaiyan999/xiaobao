
// MFCApplication7(3)View.h: CMFCApplication73View 类的接口
//

#pragma once


class CMFCApplication73View : public CView
{
protected: // 仅从序列化创建
	CMFCApplication73View() noexcept;
	DECLARE_DYNCREATE(CMFCApplication73View)

// 特性
public:
	CMFCApplication73Doc* GetDocument() const;

// 操作
public:
	CArray<CRect, CRect&>ca;
	bool set;
	int N;
	CPoint point1;
	int r;
	int a[5] = { 0,0,0,0,0 };
	
	
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCApplication73View();
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
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // MFCApplication7(3)View.cpp 中的调试版本
inline CMFCApplication73Doc* CMFCApplication73View::GetDocument() const
   { return reinterpret_cast<CMFCApplication73Doc*>(m_pDocument); }
#endif

