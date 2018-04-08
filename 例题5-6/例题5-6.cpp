// 例题5-6.cpp : 定义控制台应用程序的入口点。
//团体队列(Team Queue)：有t个团队的人正在排一个长队。每次新来一个人时，如果队伍中有他的队友，
//						则他排在最后一个队友的后面，否则，他排在队伍的最后面。
//						输入每个团队中所有队员的编号，编程使得支持下面三种指令：
//						①ENQUEUE x：编号为x的人进入长队
//						②DEQUQUE：长队的队首出队，并且输出出队的人的编号
//						③STOP：停止模拟
/*
 *	思路：对于本题，设置两个队列：
 *			①一个队列模拟整体队列的情况，比如一共有3个团队，且都有人在排队，则整体队列为：{3,1,2}，3、1、2分别为队号
 *          ②另一个队列有包括t个小队列，每个小队列记录该团队中现在正在排队的人的编号
 */

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

/* 最大团队数 */
const int maxt = 1000 + 10;

int main()
{
	int t, round = 0;
	while (scanf("%d", &t) == 1 && t)
	{
		printf("Scenario #%d\n", ++round);
		/* 用map记录下所有人的团队编号
		 * team[x]表示编号为x的人所在的队伍编号
		 */
		map<int, int> team;
		for (int i = 0; i < t; i++)
		{
			int n, x; 
			scanf("%d", &n);
			while (n--)
			{
				scanf("%d", &x);
				team[x] = i;
			}
		}

		/* 模拟队列情况 */
		queue<int> q, q2[maxt];
		for (;;)
		{
			int x;
			char cmd[10];
			/* 输入指令 */
			scanf("%s", cmd);
			/* STOP：停止模拟 */
			if (cmd[0] == 'S')
			{
				break;
			}
			/* DEQUEUE：出队，并输出出队人的编号 */
			else if (cmd[0] == 'D')
			{
				if (q.size() == 0)
				{
					printf("Empty list!\n");
					continue;
				}
				/* 获得排在队伍最前的人的队伍号 */
				int t = q.front();
				/* 先输出该人的编号，再从该队伍中删除最前面的人 */
				printf("%d\n", q2[t].front());
				q2[t].pop();
				/* 如果该人出队后，该队中无人在排队，则从整体队列中删除该队伍号 */
				if (q2[t].empty())
				{
					q.pop();
				}
			}
			/* ENQUEUE：入队 */
			else if (cmd[0] == 'E')
			{
				int x;
				/* 读入入队人的编号 */
				scanf("%d", &x);
				/* 获得入队人的队伍号 */
				int t = team[x];
				/* 若之前该团队中没有人在排队，则先在有人排队了，把队伍号加到整体队列中 */
				if (q2[t].empty())
				{
					q.push(t);
				}
				/* 将该人排在他所在的团队的队列中 */
				q2[t].push(x);
			}
		}
		printf("\n");
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

