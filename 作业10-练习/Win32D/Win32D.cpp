// Win32D.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "Win32D.h"


// ���ǵ���������һ��ʾ��
WIN32D_API int nWin32D=0;

// ���ǵ���������һ��ʾ����
WIN32D_API int fnWin32D(void)
{
    return 42;
}

WIN32D_API int GetInt()
{
	return 2020;
}

// �����ѵ�����Ĺ��캯����
// �й��ඨ�����Ϣ������� Win32D.h
CWin32D::CWin32D()
{
    return;
}
