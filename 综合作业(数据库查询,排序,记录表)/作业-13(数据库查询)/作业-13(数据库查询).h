
// ��ҵ-13(���ݿ��ѯ).h : ��ҵ-13(���ݿ��ѯ) Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C��ҵ13���ݿ��ѯApp:
// �йش����ʵ�֣������ ��ҵ-13(���ݿ��ѯ).cpp
//

class C��ҵ13���ݿ��ѯApp : public CWinApp
{
public:
	C��ҵ13���ݿ��ѯApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C��ҵ13���ݿ��ѯApp theApp;
