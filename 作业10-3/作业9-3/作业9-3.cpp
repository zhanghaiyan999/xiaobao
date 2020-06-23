// 作业9-3.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "作业9-3.h"
#define _USE_MATH_DEFINES
#include<math.h>
using namespace std;

// 这是导出变量的一个示例
MY93_API int n作业93=0;

// 这是导出函数的一个示例。
MY93_API int fn作业93(void)
{
    return 42;
}

// 这是已导出类的构造函数。
// 有关类定义的信息，请参阅 作业9-3.h
C作业93::C作业93()
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
