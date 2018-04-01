// 习题3-2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string.h>
#include <stdlib.h>
#include <stdlib.h>

#define MAXN (112)
#define SIZE (30)

double weight[MAXN];
char atom[SIZE];

int _tmain(int argc, _TCHAR* argv[])
{
	weight[67] = 12.01;
	weight[72] = 1.008;
	weight[78] = 14.01;
	weight[79] = 16.00;
	memset(atom, 0, sizeof(atom));
	scanf("%s", atom);
	double sum = 0;
	for (int i = 0; i < SIZE; i++)
	{
		if (atom[i] == 0)
		{
			break;
		}
		double base = weight[atom[i]];
		int mul = 0;
		int exp = 1;
		if (atom[i + 1] >= '1' && atom[i + 1] <= '9')
		{
			while (atom[i + 1] >= '1' && atom[i + 1] <= '9')
			{
				mul = mul * exp + (atom[i + 1] - '0');
				exp = exp * 10;
				i++;
			}
		}
		else
		{
			mul = 1;
		}
		sum += base*mul;
	}
	printf("sum = %lf\n", sum);
	system("pause");
	return 0;
}

