// 例题3-1.cpp : 定义控制台应用程序的入口点。
//替换文本中的引号

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	FILE *fin;
	fin = fopen("input.txt", "rb");
	int c;
	int q = 1;
	while ((c = fgetc(fin)) != EOF)
	{
		if (c == '"')
		{
			printf("%s", q ? "“" : "”");
			q = !q;								//q作为一个标志变量，来指示现在是左引号还是右引号
		}
		else
		{
			printf("%c", c);
		}
	}
	getchar();
	return 0;
}

