
// ��ҵ-�ۺ�ʵ��.h : ��ҵ-�ۺ�ʵ�� Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C��ҵ�ۺ�ʵ��App:
// �йش����ʵ�֣������ ��ҵ-�ۺ�ʵ��.cpp
//

class C��ҵ�ۺ�ʵ��App : public CWinApp
{
public:
	C��ҵ�ۺ�ʵ��App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C��ҵ�ۺ�ʵ��App theApp;
