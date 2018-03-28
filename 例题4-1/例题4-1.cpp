// 例题4-1.cpp : 定义控制台应用程序的入口点。
//古来的密码
/* 给定两个长度相同且不超过100的字符串，判断是否能把其中一个字符串的各个字母重排，然后对每个字母进行一一映射，使得两个字符串相同。
 * 思路：用两个数组分别统计两个字符串中各个字母出现的次数。
 *       然后，对这两个数组进行排序，如果结果相同，就说明
 *       其中一个字符串一定能够通过重排并映射后与另一字符串相同。
 *
*/

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

#define MAXN (100)

int cnt1[26] = { 0 };
int cnt2[26] = { 0 };

int cmp(const void * a, const void * b);

int _tmain(int argc, _TCHAR* argv[])
{
	char str1[MAXN];
	char str2[MAXN];
	while (1)
	{
		int flag = 1;
		scanf("%s", str1);
		scanf("%s", str2);
		/* 两个字符串长度相同 */
		int len = strlen(str1);
		for (int i = 0; i < len; i++)
		{
			cnt1[str1[i] - 'A']++;
			cnt2[str2[i] - 'A']++;
		}
		qsort(cnt1, 26, sizeof(int), cmp);
		qsort(cnt2, 26, sizeof(int), cmp);
		
		for (int i = 0; i < 26; i++)
		{
			if (cnt1[i] != cnt2[i])
			{
				flag = 0;
				break;
			}
		}
		if (flag == 0)
		{
			printf("NO\n");
		}
		else 
		{
			printf("YES\n");
		}
	}
	system("pause");
	return 0;
}

int cmp(const void *a, const void *b)
{
	/* 先对a和b进行强制类型转换 */
	/*	a>b：返回正数
	 *  a<b：返回负数
	 *  a=b：返回0
	*/
	return *(int *)a - *(int *)b;
}