// 例题3-3_书上好的算法.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define BUFFER_SIZE (30)

char *rev = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";

char *msg[] = { "not a palindrome", "a regular palindrome", "a mirrored string", "a mirrored palindrome" };

char mirrored_char(char ch)
{
	if (!isalpha(ch))
	{
		return rev[ch - '0' + 25];
	}
	else
	{
		return rev[ch - 'A'];
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	/* 使用scanf读入字符串要求变量s必要提前指明大小，所以使用 char *s是不对的 */
	char s[BUFFER_SIZE];
	/* 使用scanf的一个好处是，没有字符串结尾\r\n字符的烦恼 */
	while ((scanf("%s", s) == 1))
	{
		int len = strlen(s);
		/* 定义两个标志，分别表示是回文串，是镜像串 */
		int p = 1, m = 1;
		for (int i = 0; i < (len + 1) / 2; i++)
		{
			if (s[i] != s[len - i - 1])
			{
				/*　不是回文串　*/
				p = 0;
			}
			if (mirrored_char(s[i]) != s[len - i - 1])
			{
				/*　不是镜像串　*/
				m = 0;
			}
		}
		/* 下面的输出语句非常简单，只要一个语句就能输出所有种类的消息 */
		printf("%s -- %s.\n", s, msg[m * 2 + p]);
	}
	getchar();
	return 0;
}

