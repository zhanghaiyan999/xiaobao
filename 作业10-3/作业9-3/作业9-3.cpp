// ��ҵ9-3.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "��ҵ9-3.h"
#define _USE_MATH_DEFINES
#include<math.h>
using namespace std;

// ���ǵ���������һ��ʾ��
MY93_API int n��ҵ93=0;

// ���ǵ���������һ��ʾ����
MY93_API int fn��ҵ93(void)
{
    return 42;
}

// �����ѵ�����Ĺ��캯����
// �й��ඨ�����Ϣ������� ��ҵ9-3.h
C��ҵ93::C��ҵ93()
{
    return;
}

MY93_API int GetNum(int n)
{
	if (n > 0)
		return n;
}

MY93_API int Factorial(int n)
{
	int sum = 1;
	for (int i = n; i > 1; i--)
	{

		sum = sum*i;
	}

	return sum;
}

MY93_API float convert(float deg)
{
	float hudu;
	hudu = (deg / 180.0) * M_PI;
	return hudu;


}
