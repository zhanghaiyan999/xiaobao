
// ʵ�ֽ׳�.h : ʵ�ֽ׳� Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// Cʵ�ֽ׳�App:
// �йش����ʵ�֣������ ʵ�ֽ׳�.cpp
//

class Cʵ�ֽ׳�App : public CWinApp
{
public:
	Cʵ�ֽ׳�App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cʵ�ֽ׳�App theApp;
