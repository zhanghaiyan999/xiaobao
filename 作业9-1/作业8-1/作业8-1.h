
// ��ҵ8-1.h : ��ҵ8-1 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C��ҵ81App:
// �йش����ʵ�֣������ ��ҵ8-1.cpp
//

class C��ҵ81App : public CWinApp
{
public:
	C��ҵ81App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C��ҵ81App theApp;
