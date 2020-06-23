#include"stdafx.h"
#include"convert.h"
#include<stdio.h>
#define _USE_MATH_DEFINES
#include<math.h>
using namespace std;

char* pchar()
{
	return"½×³ËµÄÖµÎª£º";

}

int F2::GetNum(int n) {

	if (n > 0)

		return n;

}

int F2::Factorial(int n) {
	for (int i = n; i > 1; i--)
	{
		sum = sum*i;
	}

	return sum;
}
float F2::convert(float deg) {
	float hudu;
	hudu = (deg / 180.0) * M_PI;
	return hudu;


}