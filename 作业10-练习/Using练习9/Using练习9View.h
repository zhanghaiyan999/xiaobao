
// Using练习9View.h : CUsing练习9View 类的接口
//

#pragma once


class CUsing练习9View : public CView
{
protected: // 仅从序列化创建
	CUsing练习9View();
	DECLARE_DYNCREATE(CUsing练习9View)

// 特性
public:
	CUsing练习9Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CUsing练习9View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Using练习9View.cpp 中的调试版本
inline CUsing练习9Doc* CUsing练习9View::GetDocument() const
   { return reinterpret_cast<CUsing练习9Doc*>(m_pDocument); }
#endif

