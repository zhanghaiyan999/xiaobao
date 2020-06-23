
// 作业-综合实验View.h : C作业综合实验View 类的接口
//

#pragma once

class C作业综合实验Set;

class C作业综合实验View : public CRecordView
{
protected: // 仅从序列化创建
	C作业综合实验View();
	DECLARE_DYNCREATE(C作业综合实验View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MY_FORM };
#endif
	C作业综合实验Set* m_pSet;

// 特性
public:
	C作业综合实验Doc* GetDocument() const;

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
	virtual ~C作业综合实验View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	long id;
	CString name;
	long age;
	CString money;
	CString phone;
	CString picture;
	afx_msg
		void foo(CImage & img, int & sx, int & sy, int & w, int & h);
	void OnRecordFirst();
	void OnRecordPrev();
	void OnRecordNext();
	void OnRecordLast();
	void OnPaint();
	void OnBnClickedButton1();
	afx_msg void OnSort();
	afx_msg void Onadd();
	afx_msg void Onsearch();
	afx_msg void Ondelete();
	afx_msg void Onedit();
	afx_msg void Onrecord();
	afx_msg void OnBnClickedButton2();
};

#ifndef _DEBUG  // 作业-综合实验View.cpp 中的调试版本
inline C作业综合实验Doc* C作业综合实验View::GetDocument() const
   { return reinterpret_cast<C作业综合实验Doc*>(m_pDocument); }
#endif

