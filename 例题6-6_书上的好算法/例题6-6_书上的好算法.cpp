// 例题6-6_书上的好算法.cpp : 定义控制台应用程序的入口点。
//本例是书上给出的改进算法：若D=20时，I最大的下落层数可高达2^19*19 = 9961472，这将会导致创建一个巨大的数组。
//但是，仔细分析会发现，一般地，只需看小球编号的奇偶性，就能知道它是最终落在哪颗子树上。
//当I是奇数时，它是往左走的第(I+1)/2个球，当I是偶数时，它是往右走的第I/2个球。
//这样可以直接模拟最后一个球的路线。

#include "stdafx.h"
#include <cstdio>
#include <cstring>


int _tmain(int argc, _TCHAR* argv[])
{
	int D, I;
	while (scanf("%d %d", &D, &I) == 2)
	{
		int k = 1;
		for (int i = 0; i < D - 1; i++)
		{
			/* 当I是奇数时，小球往左走 */
			if (I % 2)
			{
				k = k * 2;
				I = (I + 1) / 2;
			}
			/* 当I是偶数时，小球往右走 */
			else
			{
				k = k * 2 + 1;
				I /= 2;
			}
		}
		printf("%d\n", k);
	}
	return 0;
}

