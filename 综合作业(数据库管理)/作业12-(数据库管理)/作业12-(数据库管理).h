
// ��ҵ12-(���ݿ����).h : ��ҵ12-(���ݿ����) Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C��ҵ12���ݿ����App:
// �йش����ʵ�֣������ ��ҵ12-(���ݿ����).cpp
//

class C��ҵ12���ݿ����App : public CWinApp
{
public:
	C��ҵ12���ݿ����App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C��ҵ12���ݿ����App theApp;
