// 例题4-2.cpp : 定义控制台应用程序的入口点。
//刽子手游戏
/* 因为本题的题目我没有看懂，所以直接看的答案，现在根据对答案的理解，自己实现一遍。
 */

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN (256)

/* 分别是正确的答案，用户的猜测 */
char ans[MAXN], str[MAXN];

/* 分别是用户还剩几次机会，还剩几个字母没有猜对 */
int chance, left;

/* 分别是用户猜对和猜错的标志位 */
int win = 0, lose = 0;

/* 判断子函数，判断用户猜测的该字母是否正确 */
void Guess(char ch);

int _tmain(int argc, _TCHAR* argv[])
{
	/* 当前游戏轮数 */
	int rnd = 0;
	while (((scanf("%d%s%s", &rnd, ans, str) == 3) && rnd != -1))
	{
		printf("Round %d\n", rnd);
		/* 每轮游戏之前，都要更新chance和left，以及win和lose */
		chance = 7;
		left = strlen(ans);
		win = lose = 0;
		int len = strlen(str);
		for (int i = 0; i < len; i++)
		{
			Guess(str[i]);
			/* 若有一个被置位， 则退出 */
			if (win || lose)
			{
				break;
			}
		}
		if (win)
		{
			printf("You win\n");
		}
		else if (lose)
		{
			printf("You lose\n");
		}
		else
		{
			printf("You chickened out\n");
		}
	}
	return 0;
}

void Guess(char ch)
{
	int len = strlen(ans);
	int flag = 0;
	for (int i = 0; i < len; i++)
	{
		if (ch == ans[i])
		{
			/* 还需要猜的字母个数减一 */
			--left;
			ans[i] = ' ';
			flag = 1;
			break;
		}
	}
	if (flag = 1)
	{
		/* 只有在猜错的时候，剩余机会才会减1 */
		--chance;
	}
	/* 若left变为0，则表明全部猜完 */
	if (!left)
	{
		win = 1;
	}
	/* 若可用的机会变为0， 则表明用户输了 */
	if (!chance)
	{
		lose = 1;
	}
}