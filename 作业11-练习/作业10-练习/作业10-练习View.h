
// 作业10-练习View.h : C作业10练习View 类的接口
//

#pragma once

class C作业10练习Set;

class C作业10练习View : public CRecordView
{
protected: // 仅从序列化创建
	C作业10练习View();
	DECLARE_DYNCREATE(C作业10练习View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MY10_FORM };
#endif
	C作业10练习Set* m_pSet;

// 特性
public:
	C作业10练习Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~C作业10练习View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	long ID;
	CString NAME;
	CString NUMBER;
	CString AGE;
	CString PHONE;
	afx_msg void OnEnChangeEdit3();
};

#ifndef _DEBUG  // 作业10-练习View.cpp 中的调试版本
inline C作业10练习Doc* C作业10练习View::GetDocument() const
   { return reinterpret_cast<C作业10练习Doc*>(m_pDocument); }
#endif

