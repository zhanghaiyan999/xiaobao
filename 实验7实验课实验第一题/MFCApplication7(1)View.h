
// MFCApplication7(1)View.h: CMFCApplication71View 类的接口
//

#pragma once


class CMFCApplication71View : public CView
{
protected: // 仅从序列化创建
	CMFCApplication71View() noexcept;
	DECLARE_DYNCREATE(CMFCApplication71View)

// 特性
public:
	CMFCApplication71Doc* GetDocument() const;

// 操作
public:
	
	CPoint point1;
	bool  m;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCApplication71View();
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
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFCApplication7(1)View.cpp 中的调试版本
inline CMFCApplication71Doc* CMFCApplication71View::GetDocument() const
   { return reinterpret_cast<CMFCApplication71Doc*>(m_pDocument); }
#endif

