
// ��ҵ10-1��2.h : ��ҵ10-1��2 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C��ҵ101��2App:
// �йش����ʵ�֣������ ��ҵ10-1��2.cpp
//

class C��ҵ101��2App : public CWinApp
{
public:
	C��ҵ101��2App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C��ҵ101��2App theApp;
