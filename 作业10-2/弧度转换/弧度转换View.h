
// 弧度转换View.h : C弧度转换View 类的接口
//

#pragma once


class C弧度转换View : public CView
{
protected: // 仅从序列化创建
	C弧度转换View();
	DECLARE_DYNCREATE(C弧度转换View)

// 特性
public:
	C弧度转换Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~C弧度转换View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // 弧度转换View.cpp 中的调试版本
inline C弧度转换Doc* C弧度转换View::GetDocument() const
   { return reinterpret_cast<C弧度转换Doc*>(m_pDocument); }
#endif

