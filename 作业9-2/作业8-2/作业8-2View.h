
// 作业8-2View.h : C作业82View 类的接口
//

#pragma once


class C作业82View : public CView
{
protected: // 仅从序列化创建
	C作业82View();
	DECLARE_DYNCREATE(C作业82View)

// 特性
public:
	C作业82Doc* GetDocument() const;

// 操作
public:
	int x1;
	int y1;
	int x2;
	int y2;
	CRect A;
	int flag;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~C作业82View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 作业8-2View.cpp 中的调试版本
inline C作业82Doc* C作业82View::GetDocument() const
   { return reinterpret_cast<C作业82Doc*>(m_pDocument); }
#endif

