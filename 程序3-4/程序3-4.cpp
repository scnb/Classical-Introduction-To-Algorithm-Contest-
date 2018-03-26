// 程序3-4.cpp : 定义控制台应用程序的入口点。
//计算并列出竖式

#include "stdafx.h"
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

char s[20]; 
char buf[100];


int _tmain(int argc, _TCHAR* argv[])
{
	int count = 0;
	int ok = 1;
	scanf("%s", s);
	for (int abc = 111; abc < 1000; abc++)
	{
		for (int de = 11; de < 100;de++)
		{
			ok = 1;
			int temp1 = abc*(de % 10);
			int temp2 = abc*(de / 10);
			int sum = abc*de;
			sprintf(buf, "%d%d%d%d%d", abc, de, temp1, temp2, sum);
			for (unsigned int k = 0; k < strlen(buf); k++)
			{
				if (!strchr(s, buf[k]))
				{
					ok = 0;
					break;
				}
			}
			if (ok)
			{
				count++;
				printf("<%d>\n%5d\nX%4d\n-----\n%5d\n%4d\n-----\n%5d", count, abc, de, temp1, temp2, sum);
			}
		}
	}
	getchar();
	getchar();
	return 0;
}

