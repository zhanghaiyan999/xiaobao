
// 作业10-3Doc.h : C作业103Doc 类的接口
//


#pragma once
#include "作业10-3Set.h"


class C作业103Doc : public CDocument
{
protected: // 仅从序列化创建
	C作业103Doc();
	DECLARE_DYNCREATE(C作业103Doc)

// 特性
public:
	C作业103Set m_作业103Set;

// 操作
public:

// 重写
public:
	virtual BOOL OnNewDocument();
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~C作业103Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
