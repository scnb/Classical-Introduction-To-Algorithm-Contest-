// 例题3-5_书上的好算法.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN (100005)

int ans[MAXN];

int _tmain(int argc, _TCHAR* argv[])
{
	int count = 0;
	int n;
	/* 通过memset函数将ans数组赋初值为0 */
	memset(ans, 0, sizeof(ans));
	for (int m = 1; m < MAXN; m++)
	{
		int original_number = m;
		int sum = m;
		/* 通过循环计算m及其各位上的数字之和 */
		while (original_number > 0)
		{
			sum += original_number % 10;
			original_number = original_number / 10;
		}
		/* 如果数组该元素还没有存过数据，或者当前计算的生成元是最小的，那么就保存该生成元 */
		if (ans[sum] == 0 || m < ans[sum])
		{
			ans[sum] = m;
		}
	}

	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		printf("%d\n", ans[n]);
	}
	system("pause");
	return 0;
}

