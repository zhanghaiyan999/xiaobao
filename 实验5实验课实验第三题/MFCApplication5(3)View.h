
// MFCApplication5(3)View.h: CMFCApplication53View 类的接口
//

#pragma once


class CMFCApplication53View : public CView
{
protected: // 仅从序列化创建
	CMFCApplication53View() noexcept;
	DECLARE_DYNCREATE(CMFCApplication53View)

// 特性
public:
	CMFCApplication53Doc* GetDocument() const;

// 操作
public:
	
	CPoint OldPoint;
	CPoint startPoint;
	bool   startRect;
	int flag;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCApplication53View();
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
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void On32773();
	afx_msg void On32774();
	afx_msg void On32775();
};

#ifndef _DEBUG  // MFCApplication5(3)View.cpp 中的调试版本
inline CMFCApplication53Doc* CMFCApplication53View::GetDocument() const
   { return reinterpret_cast<CMFCApplication53Doc*>(m_pDocument); }
#endif

