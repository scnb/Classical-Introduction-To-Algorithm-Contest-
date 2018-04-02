// 习题3-3.cpp : 定义控制台应用程序的入口点。
//数数字，这道题非常简单。

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxSize (10000)

char input[maxSize];
int count[10] = { 0 };

int _tmain(int argc, _TCHAR* argv[])
{
	scanf("%s", input);
	int len = strlen(input);
	for (int i = 0; i < len; i++)
	{
		count[input[i] - '0']++;
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", count[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}

