
// ��ҵ11-2(�Ի���ͼƬ).h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C��ҵ112�Ի���ͼƬApp: 
// �йش����ʵ�֣������ ��ҵ11-2(�Ի���ͼƬ).cpp
//

class C��ҵ112�Ի���ͼƬApp : public CWinApp
{
public:
	C��ҵ112�Ի���ͼƬApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C��ҵ112�Ի���ͼƬApp theApp;