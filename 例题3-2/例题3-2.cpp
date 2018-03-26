// 例题3-2.cpp : 定义控制台应用程序的入口点。
//修复键盘输入错误

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

char key_table[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

int _tmain(int argc, _TCHAR* argv[])
{
	FILE *fin;
	fin = fopen("input.txt", "rb");
	int c;
	int i;
	while ((c = fgetc(fin)) != EOF)
	{
		if (c == '\n' || c == ' ')
		{
			printf("%c", c);
		}
		else
		{
			/* 通过循环来找到该字符在数组中的索引 */
			for (i = 0; key_table[i] && c != key_table[i]; i++);
			/* 修复了书上的BUG，即` Q A Z这四个是特殊位置，不可能是其他的字符向左错位导致的 */
			if (key_table[i] && i!=0 && i!=13 && i!=26 && i!=37)
			{
				printf("%c", key_table[i - 1]);
			}
			else
			{
				putchar(c);
			}
		}
	}
	getchar();
	return 0;
}

