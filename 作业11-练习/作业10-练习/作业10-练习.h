
// ��ҵ10-��ϰ.h : ��ҵ10-��ϰ Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C��ҵ10��ϰApp:
// �йش����ʵ�֣������ ��ҵ10-��ϰ.cpp
//

class C��ҵ10��ϰApp : public CWinApp
{
public:
	C��ҵ10��ϰApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C��ҵ10��ϰApp theApp;
