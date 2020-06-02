
// MFCApplication5class(1).h: MFCApplication5class(1) 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // 主符号


// CMFCApplication5class1App:
// 有关此类的实现，请参阅 MFCApplication5class(1).cpp
//

class CMFCApplication5class1App : public CWinAppEx
{
public:
	CMFCApplication5class1App() noexcept;


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCApplication5class1App theApp;
