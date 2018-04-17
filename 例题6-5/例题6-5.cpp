// 例题6-5.cpp : 定义控制台应用程序的入口点。
//移动盒子（Boxes in Line）：有一行盒子，从左到右一次编号为1,2,3……n，可以执行以下4中命令：
//①1 X Y 表示把盒子X移动到盒子Y的左边 （已经在左边则忽略该命令）
//②2 X Y 表示把盒子X移动到盒子Y的右边 （已经在右边则忽略该命令）
//③3 X Y 表示交换盒子X和Y的位置
//④4     表示翻转链表
/*	思路：考虑用双向链表（顺序存储）来实现。用left[i]和right[i]分别表示编号为i的盒子左右两边的盒子编号
 *  另外，翻转链表的操作比价占用时间，可以考虑用一个标记来表示是否翻转了链表，比如inv=1时，表示将链表翻转
 *  而再次翻转inv=0，又回到了原来的状态，这样翻转这一费时间的操作不用真正的执行。
 *  但是需要注意的是，加上了inv标记，则有些操作比如1和2就需要格外注意，比如翻转之后，这行1操作实际上就要反着来，相当于
 *  执行2操作，执行2操作也是同理，所以，当inv=1时，op=3-op
*/

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string>

#define maxSize (100000+10)

/* 分别表示第i个盒子左右盒子的编号 */
int left[maxSize];
int right[maxSize];

/* 将两个节点相互连接 */
void link(int L, int R)
{
	right[L] = R;
	left[R] = L;
}


int _tmain(int argc, _TCHAR* argv[])
{
	int m, kase = 0;
	int n;
	/* n表示盒子个数，m表示指令的条数 */
	while (scanf("%d %d", &n, &m) == 2)
	{
		/* 将盒子相互连接 */
		for (int i = 1; i <= n; i++)
		{
			left[i] = i - 1;
			right[i] = (i + 1) % (n + 1);
		}
		left[0] = n;
		right[0] = 1;
		int op, X, Y, inv = 0;
		while (m--)
		{
			scanf("%d", &op);
			if (op == 4)
			{
				/* 将链表翻转 */
				inv = !inv;
			}
			else
			{
				scanf("%d %d", &X, &Y);
				/* 若翻转了链表，则该操作已经和原来的操作是相反的 */
				if (op != 3 && inv)
				{
					op = 3 - op;
				}
				/* 若操作为1， 且X已经在Y的右边了，则跳过该命令 */
				if (op == 1 && left[Y] == X)
				{
					continue;
				}
				if (op == 2 && right[Y] == X)
				{
					continue;
				}

				int LX = left[X], RX = right[X], LY = left[Y], RY = right[Y];
				if (op == 1)
				{
					link(LX, RX);
					link(LY, X);
					link(X, Y);
				}
				else if (op == 2)
				{
					link(LX, RX);
					link(Y, X);
					link(X, RY);
				}
				else if (op == 3)
				{
					if (right[X] == Y)
					{
						link(LX, Y);
						link(Y, X);
						link(X, RY);
					}
					else if (right[Y] == X)
					{
						link(LY, X);
						link(X, Y);
						link(Y, RX);
					}
					else
					{
						link(LX, Y);
						link(Y, RX);
						link(LY, X);
						link(X, RY);
					}
				}
			}
		}
		int b = 0;
		long long ans = 0;
		/* 计算奇数位置上的和 */
		for (int i = 1; i <= n; i++)
		{
			b = right[b];
			if (i % 2 == 1)
			{
				ans += b;
			}
		}
		/* 如果链表翻转过了， 并且有偶数个元素， 则ans等于所有数的和减去ans */
		if (inv && n % 2 == 0)
		{
			ans = (long long)n*(n + 1) / 2 - ans;
		}
		printf("Case %d: %lld\n", ++kase, ans);
	}
	return 0;
}

