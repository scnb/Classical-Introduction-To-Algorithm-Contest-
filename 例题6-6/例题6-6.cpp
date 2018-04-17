// 例题6-6.cpp : 定义控制台应用程序的入口点。
//小球下落（Dropping Balls）：有一棵二叉树，最大深度为D，且所有叶子深度都相同（即满二叉树）。根节点编号为1，依次往后编号。
//每个内节点上都有一个开关，初始全部关闭，当每次有一个小球落到一个开关上时，状态都会改变。当小球到达一个内节点的时候，
//如果该节点时关，则往左走，否则往右走，知道走到叶子节点。

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <math.h>
#include <cstdlib>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	int D, I;
	while (scanf("%d %d", &D, &I) == 2)
	{
		int Size = pow(2, D);
		int pos = 1;
		int *tree = new int[Size];
		memset(tree, 0, Size*sizeof(int));
		for (int i = 0; i < I;i++)
		{
			pos = 1;
			while (pos * 2 < Size)
			{
				/* 0代表关闭，则小球走向左子树 */
				if (tree[pos] == 0)
				{
					tree[pos] = !tree[pos];
					pos = pos * 2;
				}
				/* 否则小球走向右子树 */
				else
				{
					tree[pos] = !tree[pos];
					pos = pos * 2 + 1;
				}
			}
		}
		cout << pos << endl;
	}
	return 0;
}

