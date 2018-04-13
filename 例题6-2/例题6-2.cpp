// 例题6-2.cpp : 定义控制台应用程序的入口点。
//铁轨（Rails）：有n节车厢从A方向驶入车站，按进站顺序编号1-n。判断能否让它们按照某种特定的顺序进入B方向的车站。
/*	本题的重点就是根据出栈的顺序来判断是否能这样出栈。
 *  跟数据结构考研题有些类似， 告诉你一个进站的序列， 问一下哪些出栈顺序不正确。
 *  比如出栈顺序5 4 1 2 3， 在1这个地方出现了错误，若5和4先出栈，则说明之前1 2 3一定已经进站
 *  且1在栈底，但是1绝对不能在4之后出栈。
*/


#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <stack>

using namespace std;

#define maxSize (1000+10)

int n, target[maxSize];

int _tmain(int argc, _TCHAR* argv[])
{
	while (scanf("%d", &n) == 1)
	{
		stack<int> s;
		/* B用来指向当前是哪个出栈元素， A用来记录该元素之前的正确进栈顺序 */
		int A = 1, B = 1;
		/* 输入出栈的顺序 */
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &target[i]);
		}
		int ok = 1;
		/* 下面while循环的思路非常牛，用来判断一个出栈元素之前的进站顺序 */
		while (B <= n)
		{
			if (A == target[B])
			{
				A++;
				B++;
			}
			else if (!s.empty() && s.top() == target[B])
			{
				s.pop();
				B++;
			}
			else if (A <= n)
			{
				s.push(A++);
			}
			else
			{
				ok = 0;
				break;
			}
		}
		printf("%s\n", ok ? "yes" : "no");
	}
	system("pause");
	return 0;
}

