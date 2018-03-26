// 例题3-3.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>

using namespace std;

char mirror[] = "A   3  HIL JM O   2TUVWX51SE Z  8 ";
#define  buffer_size (80)

int is_Palindromes(const char *s);
int is_Mirror(const char *s);

int _tmain(int argc, _TCHAR* argv[])
{
	FILE *fin;
	fin = fopen("input.txt", "rb");
	/* 不能使用 char *s;这样没有声明s的大小的话，fgets会报错 */
	char s[buffer_size] = "";
	while (fgets(s, buffer_size, fin)!=NULL)
	{
		char temp[buffer_size] = "";
		/* 对于文件中的最后一行数据需要特别注意，因为该行后面没有 \r\n */
		if (s[strlen(s) - 1] == '\n' || s[strlen(s) - 1] == '\r')
		{
			strncpy(temp, s, strlen(s) - 2);
		}
		else
		{
			strncpy(temp, s, strlen(s));
		}
		if (is_Palindromes(temp))
		{
			if (is_Mirror(temp))
			{
				printf("%s -- is a mirrored palindrome\n", temp);
			}
			else
			{
				printf("%s -- is a regular palindrome\n", temp);
			}
		}
		else
		{
			if (is_Mirror(temp))
			{
				printf("%s -- is a mirrored string\n", temp);
			}
			else
			{
				printf("%s -- is not a palindrome\n", temp);
			}
		}
	}
	getchar();
	return 0;
}

/*　判断该字符串是不是回文字符串　*/
int is_Palindromes(const char *s)
{
	/* 利用string.h中的strrev函数 */
	char temp[buffer_size] = "";
	/* 必须要保护s不能使其内容改变 */
	strcpy(temp, s);
	_strrev(temp);
	/* 不能使用 == 来判断字符串是否相等，必须用库函数 */
	if (!strcmp(temp, s))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/*　判断该字符串是不是镜像字符串　*/
int is_Mirror(const char *s)
{
	char temp[buffer_size] = "";
	strcpy(temp, s);
	_strrev(temp);
	int len = strlen(temp);
	int middle_odd = len / 2;
	for (int i = 0; i < len; i++)
	{
		if (i == middle_odd && middle_odd % 2 == 1)
		{
			continue;
		}
		if (mirror[s[i] - 'A'] == temp[i] || mirror[temp[i] - '0' + 25] == s[i])
		{
			continue;
		}
		else
		{
			return 0;
		}
	}
	return 1;
}