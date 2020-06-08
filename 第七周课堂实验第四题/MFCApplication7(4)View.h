
// MFCApplication7(4)View.h: CMFCApplication74View 类的接口
//

#pragma once


class CMFCApplication74View : public CView
{
protected: // 仅从序列化创建
	CMFCApplication74View() noexcept;
	DECLARE_DYNCREATE(CMFCApplication74View)

// 特性
public:
	CMFCApplication74Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCApplication74View();
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
	afx_msg void On32771();
};

#ifndef _DEBUG  // MFCApplication7(4)View.cpp 中的调试版本
inline CMFCApplication74Doc* CMFCApplication74View::GetDocument() const
   { return reinterpret_cast<CMFCApplication74Doc*>(m_pDocument); }
#endif

