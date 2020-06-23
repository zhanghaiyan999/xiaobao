
// 动态链接View.h : C动态链接View 类的接口
//

#pragma once


class C动态链接View : public CView
{
protected: // 仅从序列化创建
	C动态链接View();
	DECLARE_DYNCREATE(C动态链接View)

// 特性
public:
	C动态链接Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~C动态链接View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // 动态链接View.cpp 中的调试版本
inline C动态链接Doc* C动态链接View::GetDocument() const
   { return reinterpret_cast<C动态链接Doc*>(m_pDocument); }
#endif

