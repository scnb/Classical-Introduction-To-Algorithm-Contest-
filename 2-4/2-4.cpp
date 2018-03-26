// 2-4.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
using namespace std;



int _tmain(int argc, _TCHAR* argv[])
{
	FILE *fin;
	fin = fopen("Text.txt", "rb");
	int n, m;
	double sum = 0;
	while ((fscanf(fin, "%d %d", &n, &m) == 2) && ((n!=0)&&(m!=0)))
	{
		sum = 0;
		for (int i = n; i <= m; i++)
		{
			double temp = i*1.0;
			sum += (1.0) / temp / temp;
		}
		printf("%.5f\n", sum);
	}
	getchar();
	return 0;
}

