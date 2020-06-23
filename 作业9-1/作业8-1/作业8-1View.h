
// 作业8-1View.h : C作业81View 类的接口
//

#pragma once


class C作业81View : public CView
{
protected: // 仅从序列化创建
	C作业81View();
	DECLARE_DYNCREATE(C作业81View)

// 特性
public:
	C作业81Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~C作业81View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnViewStudentlist();
};

#ifndef _DEBUG  // 作业8-1View.cpp 中的调试版本
inline C作业81Doc* C作业81View::GetDocument() const
   { return reinterpret_cast<C作业81Doc*>(m_pDocument); }
#endif

