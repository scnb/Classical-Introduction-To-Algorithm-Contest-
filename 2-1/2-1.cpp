// 2-1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

int cube(int a);

using namespace std;

int main(int argc, _TCHAR* argv[])
{
	int i = 100;
	int ge;
	int shi;
	int bai;
	for (; i < 1000; i++)
	{
		ge = i % 10;
		shi = i % 100 / 10;
		bai = i / 100;
		if (i == cube(ge) + cube(shi) + cube(bai))
		{
			cout << i << endl;
		}
	}
	getchar();
	return 0;
}

int cube(int a)
{
	return a*a*a;
}