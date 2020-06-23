
// Using练习9.h : Using练习9 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// CUsing练习9App:
// 有关此类的实现，请参阅 Using练习9.cpp
//

class CUsing练习9App : public CWinApp
{
public:
	CUsing练习9App();


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CUsing练习9App theApp;
