
// ��ҵ10-3.h : ��ҵ10-3 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C��ҵ103App:
// �йش����ʵ�֣������ ��ҵ10-3.cpp
//

class C��ҵ103App : public CWinApp
{
public:
	C��ҵ103App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C��ҵ103App theApp;
