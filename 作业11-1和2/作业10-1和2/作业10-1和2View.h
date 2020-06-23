
// 作业10-1和2View.h : C作业101和2View 类的接口
//

#pragma once

class C作业101和2Set;

class C作业101和2View : public CRecordView
{
protected: // 仅从序列化创建
	C作业101和2View();
	DECLARE_DYNCREATE(C作业101和2View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MY1012_FORM };
#endif
	C作业101和2Set* m_pSet;

// 特性
public:
	C作业101和2Doc* GetDocument() const;

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
	virtual ~C作业101和2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnChangeEdit1();
	long ID;
	CString name;
	CString number;
	CString age;
	CString phone;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeEdit3();
	void foo(CImage& img, int &sx, int &sy, int &w, int &h);
	afx_msg void OnEnChangeEdit5();
};

#ifndef _DEBUG  // 作业10-1和2View.cpp 中的调试版本
inline C作业101和2Doc* C作业101和2View::GetDocument() const
   { return reinterpret_cast<C作业101和2Doc*>(m_pDocument); }
#endif

