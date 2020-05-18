
// shiyan3(3)View.h: Cshiyan33View 类的接口
//

#pragma once


class Cshiyan33View : public CView
{
protected: // 仅从序列化创建
	Cshiyan33View() noexcept;
	DECLARE_DYNCREATE(Cshiyan33View)

// 特性
public:
	Cshiyan33Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Cshiyan33View();
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

#ifndef _DEBUG  // shiyan3(3)View.cpp 中的调试版本
inline Cshiyan33Doc* Cshiyan33View::GetDocument() const
   { return reinterpret_cast<Cshiyan33Doc*>(m_pDocument); }
#endif

