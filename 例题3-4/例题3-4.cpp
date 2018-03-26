// 例题3-4.cpp : 定义控制台应用程序的入口点。
//本题稍微有些难度，最终是在自己的第一次的框架上加上书上的参考代码完成的。
/*	主要参考了书上代码的一下部分：
 *	①序列都定义为int型字符串，而不是char型字符串，这样使用scanf读入的时候就可以自动忽略空格，且方便和flag数组交互
 *  ②一边读取用户的输入一边进行比较，计算出A的值
 *  另外，在计算B的值时，使用的方法和书上代码不一样，但是思想用的是书上的思想：即统计两个序列中每个数字出现的次数，
 *  用一个数组来统计每个数字的出现次数是非常方便的，定义一个包含10个整形元素的数组来存放该次数。
 *  然后，对于这1-9共10个数字，通过循环，分别让B加上两个数组中相同索引位置的元素中的最小值，最后别忘了还要减去A，
 *  因为A代表在同一位置上数字相同的个数。
*/

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

#define MAXN (100)

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	int A, B;
	int count = 0;
	/* 当n输入为0时，程序退出 */
	while ((scanf("%d", &n) == 1 && n != 0))
	{
		A = 0;
		B = 0;
		printf("Game %d:\n", ++count);
		/* 逐个读入标准答案 */
		int answer[MAXN];
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &answer[i]);
		}

		/*　循环读取用户的猜测，直到输入全0为止 */
		while (1)
		{
			int flag_1[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
			int flag_2[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
			int temp[MAXN];
			/* 一边读取用户输入，一边判断是否和标准答案相等 */
			for (int i = 0; i < n; i++)
			{
				scanf("%d", &temp[i]);
				if (temp[i] == answer[i])
				{
					A++;
				}
			}

			/* 若用户的输入为0，则表示该组数据结束，退出while(1)循环 */
			if (temp[0] == 0)
			{
				break;
			}

			/*　统计两个序列中各个数字出现的次数　*/
			for (int i = 0; i < n; i++)
			{
				flag_1[answer[i]]++;
				flag_2[temp[i]]++;
			}

			for (int i = 1; i < 10; i++)
			{
				/* 获得同一个数字在序列1和序列2中出现次数的最小值 */
				int min = (flag_1[i] < flag_2[i]) ? flag_1[i] : flag_2[i];
				B += min;
			}
			/* 别忘了减去A，A代表相同位置上数字相同的个数 */
			B -= A;
			printf("	(%d,%d)\n",A, B);
			/* 在下一次循环开始之前要把A和B清零 */
			A = 0;
			B = 0;
		}
	}
	return 0;
}

