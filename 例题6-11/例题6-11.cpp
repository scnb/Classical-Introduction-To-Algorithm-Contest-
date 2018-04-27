// 例题6-11.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <cstring>

const int len = 32;
const int maxn = 1024 + 10;
char s[maxn];
int buf[len][len], cnt;

/* 把字符串s导出到以(r,c)为左上角，边长为w的缓冲区中 */
//2 1
//3 4
void draw(const char *s, int &p, int r, int c, int w)
{
	char ch = s[p++];
	/* 递归地把图画出来 */
	if (ch == 'p')
	{
		draw(s, p, r, c + w / 2, w / 2);			//第1个
		draw(s, p, r, c, w / 2);					//第2个
		draw(s, p, r + w / 2, c, w / 2);			//第3个
		draw(s, p, r + w / 2, c + w / 2, w / 2);	//第4个
	}
	/* 只画黑色像素 */
	else if (ch == 'f')
	{
		for (int i = r; i < r + w; i++)
		{
			for (int j = c; j < c + w; j++)
			{
				if (buf[i][j] == 0)
				{
					buf[i][j] = 1;
					cnt++;			//记录黑色像素的个数
				}
			}
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		memset(buf, 0, sizeof(buf));
		cnt = 0;
		for (int i = 0; i < 2; i++)
		{
			scanf("%s", s);
			int p = 0;
			draw(s, p, 0, 0, len);
		}
		printf("There are %d black pixels.\n", cnt);
	}
	return 0;
}

