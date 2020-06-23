
// 作业10-3View.h : C作业103View 类的接口
//

#pragma once

class C作业103Set;

class C作业103View : public CRecordView
{
protected: // 仅从序列化创建
	C作业103View();
	DECLARE_DYNCREATE(C作业103View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MY103_FORM };
#endif
	C作业103Set* m_pSet;

// 特性
public:
	C作业103Doc* GetDocument() const;

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
	virtual ~C作业103View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	CString iD;
	CString NAME;
	afx_msg void OnEnChangeEdit3();
	long number;
	long age;
	long phone;
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
	void C作业103View::foo(CImage&img, int&sx, int&sy, int&w, int&h);
	afx_msg void OnPaint();
};

#ifndef _DEBUG  // 作业10-3View.cpp 中的调试版本
inline C作业103Doc* C作业103View::GetDocument() const
   { return reinterpret_cast<C作业103Doc*>(m_pDocument); }
#endif

