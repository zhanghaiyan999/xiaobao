
// ��ҵ8-��ϰ1.h : ��ҵ8-��ϰ1 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C��ҵ8��ϰ1App:
// �йش����ʵ�֣������ ��ҵ8-��ϰ1.cpp
//

class C��ҵ8��ϰ1App : public CWinApp
{
public:
	C��ҵ8��ϰ1App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C��ҵ8��ϰ1App theApp;
