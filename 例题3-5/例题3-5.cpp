// 例题3-5.cpp : 定义控制台应用程序的入口点。
//求解生成元
/*生成元：一个数ｘ，加上ｘ的各个位上的数字得到数字ｙ，则称数字ｘ是数字ｙ的生成元。
 *例如：y = 216, 则x = 198就是216的一个生成元
 *给定一个输入n，编程求解其最小生成元，如果不存在则输出0.
*/

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int get_single_sum(int i);

int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	int flag;
	while (scanf("%d", &n) == 1)
	{
		flag = 0;
		for (int i = 0; i < n; i++)
		{
			int single_sum = get_single_sum(i);
			if (i + single_sum == n)
			{
				printf("%d\n", i);
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			printf("%d\n", 0);
		}
	}
	return 0;
}

int get_single_sum(int i)
{
	int ret = 0;
	while (i > 0)
	{
		ret += i % 10;
		i = i / 10;
	}
	return ret;
}