// 例题4-4.cpp : 定义控制台应用程序的入口点。
//信息解码：这道题题干看了三遍才看懂。比较复杂，最后是看了答案才有点感觉的。

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int readchar();
int readint(int c);

int code[8][1 << 8];	// 1<<8表示2^8
int readcodes();

int _tmain(int argc, _TCHAR* argv[])
{
	/* 循环读入编码 */
	while (readcodes())
	{
		for (;;)
		{
			/* 连续读取三个二进制数字，算出该小节中每个编码的长度 */
			int len = readint(3);
			/* 当编码长度为0时，退出程序 */
			if (len == 0)
			{
				break;
			}
			for (;;)
			{
				int v = readint(len);
				/* (1<<len) - 1算出了该小节编码的结束编码
				 * 例如len = 2， 则结束编码为：1<<2 = 二进制(100) = 十进制(4)
				 * 再 4 - 1 = 3，得到结束编码是 二进制(011) = 十进制(3)
				*/
				if (v == (1 << len) - 1)
				{
					break;
				}
				putchar(code[len][v]);
			}
		}
		putchar('\n');
	}
	system("pause");
	return 0;
}

int readchar()
{
	for (;;)
	{
		int ch = getchar();
		/* 当读入的字符不是换行符时，则返回读入的字符 */
		if (ch != '\n' && ch != '\r')
		{
			return ch;
		}
	}
}

int readint(int c)
{
	int v = 0;
	/* 连续读入c个二进制数字，并计算其十进制值 
	 * 例如：c = 3，连续3个二进制数是010
	 * c = 3: v = 0 * 2 + 0 - 0 = 0
	 * c = 2: v = 0 * 2 + 1 - 0 = 1
	 * c = 1: v = 1 * 2 + 0 - 0 = 2
	*/
	while (c--)
	{
		v = v * 2 + readchar() - '0';
	}
	return v;
}

int readcodes()
{
	/* 在每一轮读入编码之前，都要将数组清空 */
	memset(code, 0, sizeof(code));
	code[1][0] = readchar();
	for (int len = 2; len <= 7; len++)
	{
		for (int i = 0; i < (1 << len) - 1; i++)
		{
			int ch = getchar();
			/* 若再没有更多的编码，则返回0，退出while循环 */
			if (ch == EOF)
			{
				return 0;
			}
			/* 若读到的是换行符，则表明后面还有数据，返回1，继续读取编码 */
			if (ch == '\n' || ch == '\r')
			{
				return 1;
			}
			code[len][i] = ch;
		}
	}
	return 1;
}