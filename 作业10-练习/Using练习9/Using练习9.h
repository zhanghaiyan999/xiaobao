
// Using��ϰ9.h : Using��ϰ9 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CUsing��ϰ9App:
// �йش����ʵ�֣������ Using��ϰ9.cpp
//

class CUsing��ϰ9App : public CWinApp
{
public:
	CUsing��ϰ9App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CUsing��ϰ9App theApp;
