
// ��ҵ11-1(�Ŵ�ͼƬ).h : ��ҵ11-1(�Ŵ�ͼƬ) Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C��ҵ111�Ŵ�ͼƬApp:
// �йش����ʵ�֣������ ��ҵ11-1(�Ŵ�ͼƬ).cpp
//

class C��ҵ111�Ŵ�ͼƬApp : public CWinApp
{
public:
	C��ҵ111�Ŵ�ͼƬApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C��ҵ111�Ŵ�ͼƬApp theApp;
