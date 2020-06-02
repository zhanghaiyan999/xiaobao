
// MFCApplication6class(1)View.h: CMFCApplication6class1View 类的接口
//

#pragma once


class CMFCApplication6class1View : public CView
{
protected: // 仅从序列化创建
	CMFCApplication6class1View() noexcept;
	DECLARE_DYNCREATE(CMFCApplication6class1View)

// 特性
public:
	CMFCApplication6class1Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCApplication6class1View();
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
	afx_msg void OnFileOpen();
	afx_msg void OnPaint();
};

#ifndef _DEBUG  // MFCApplication6class(1)View.cpp 中的调试版本
inline CMFCApplication6class1Doc* CMFCApplication6class1View::GetDocument() const
   { return reinterpret_cast<CMFCApplication6class1Doc*>(m_pDocument); }
#endif

