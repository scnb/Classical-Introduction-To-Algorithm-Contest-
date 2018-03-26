// 例题3-6.cpp : 定义控制台应用程序的入口点。
//环状序列：
/* 长度为n的环状串有n中表示方法，其中字典序最小的称为“最小表示”
 * 字典序：对于两个字符串，从第一个字符开始比较，当某一位置的字符不同时，该位置字符较小的串，字典序较小。
 * 输入一个环状DNA序列，输出其最小表示。
*/

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN (105)

char str[MAXN];

int Is_less(const char *s, int p, int q);

int _tmain(int argc, _TCHAR* argv[])
{
	int count = 0;
	int ans = 0;	//最小串的起点
	scanf("%d", &count);
	while (count--)
	{
		scanf("%s", str);
		ans = 0;
		int len = strlen(str);
		for (int i = 1; i < len; i++)
		{
			if (Is_less(str, i, ans))
			{
				ans = i;
			}
		}

		for (int i = ans; i < ans + len; i++)
		{
			printf("%c", str[i%len]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}

/* p代表当前字符串的起始位置，q代表最小串的起始位置 */
int Is_less(const char *s, int p, int q)
{
	int len = strlen(s);
	for (int i = 0; i < len; i++)
	{
		if (s[(p + i)%len] != s[(q + i)%len])
		{
			return s[(p+i)%len] < s[(q+i)%len];
		}
	}
}