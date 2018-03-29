// 例题4-3.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN (25)

int n, k, m;
int count;
int pos_A, pos_B;
int people[MAXN];
int Choose(int people[MAXN], int pos, int flag);

int main()
{
	scanf("%d%d%d", &n, &k, &m);
	for (int i = 1;i <= n;i++)
	{
		people[i] = i;
	}
	count = n;
	pos_A = 1;
	pos_B = n;
	while (count > 0)
	{
		/* 官员A、B分别挑人 */
		pos_A = Choose(people, pos_A, 0);
		pos_B = Choose(people, pos_B, 1);
		if (pos_A != pos_B)
		{
			printf("%3d %3d\n", pos_A, pos_B);
			count -= 2;
		}
		else
		{
			printf("%3d\n", pos_A);
			count -= 1;
		}
		people[pos_A] = people[pos_B] = 0;
	}
	system("pause");
}

int Choose(int people[MAXN], int pos, int flag)
{
	/* 官员A */
	if (flag == 0)
	{
		/* 要走过k个人，包括起始的那一个人 */
		int step = k;
		while (1)
		{
			if (people[pos] != 0)
			{
				if (step > 1)
				{
					--step;
					pos = (pos++) % n;
				}
				else
				{
					return pos;
				}
			}
			else
			{
				pos = (pos++) % n;
			}
		}
	}

	if (flag == 1)
	{
		int step = m;
		while (1)
		{
			if (people[pos] != 0)
			{
				if (step > 1)
				{
					--step;
					pos--;
					if (pos < 1)
					{
						pos = 10;
					}
				}
				else
				{
					return pos;
				}
			}
			else
			{
				pos--;
				if (pos < 1)
				{
					pos = 10;
				}
			}
		}
	}
}
