// 习题3-1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXN (80)

char str[MAXN];

int _tmain(int argc, _TCHAR* argv[])
{
	scanf("%s", str);
	int count = 0;
	int sum = 0;
	for (int i = 0; i < 80; i++)
	{
		if (str[i] == 'O')
		{
			count++;
			sum += count;
		}
		else
		{
			count = 0;
		}
	}
	printf("sum = %d\n", sum);
	system("pause");
	return 0;
}