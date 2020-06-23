
// 实现阶乘View.h : C实现阶乘View 类的接口
//

#pragma once


class C实现阶乘View : public CView
{
protected: // 仅从序列化创建
	C实现阶乘View();
	DECLARE_DYNCREATE(C实现阶乘View)

// 特性
public:
	C实现阶乘Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~C实现阶乘View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // 实现阶乘View.cpp 中的调试版本
inline C实现阶乘Doc* C实现阶乘View::GetDocument() const
   { return reinterpret_cast<C实现阶乘Doc*>(m_pDocument); }
#endif

