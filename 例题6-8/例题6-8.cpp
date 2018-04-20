// 例题6-8.cpp : 定义控制台应用程序的入口点。
//树（Tree）：给一棵结点带权的二叉树的中序和后序遍历序列，找一个叶子结点使得它到根的路径上的权和最小。
//如果有多解，该叶子本身的权值应尽可能小。
//输入中每两行表示一棵树，第一行为中序遍历，第二行为后序遍历。

/*	答案用的数组，可以考虑用链表来表示二叉树来解决问题
*/

#include "stdafx.h"
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <algorithm>
#include <iostream>

using namespace std;

typedef struct BTNode
{
	int data;
	struct BTNode *left;
	struct BTNode *right;
}BTNode;

BTNode *root = new BTNode;


const int maxv = 1000 + 10;

/* 分别是中序序列， 后序序列，当前结点的左子树根结点， 当前结点的右子树根结点 */
int in_order[maxv], post_order[maxv], lch[maxv], rch[maxv];

int n;

/* 目前的最优解和对应的权值和 */
int best, best_sum;

/* 读入序列 */
bool read_list(int *a)
{
	string line;
	if (!getline(cin, line))
	{
		return false;
	}
	stringstream ss(line);
	n = 0;
	int x;
	while (ss >> x)
	{
		a[n++] = x;
	}
	return x > 0;
}


/* 根据中序遍历序列和后序遍历序列构建一棵树 */
int build(int L1, int R1, int L2, int R2)
{
	if (L1 > R1)
	{
		return 0;
	}
	/* 取得当前树的根结点 */
	int root = post_order[R2];
	int p = L1;
	while (in_order[p] != root)
	{
		p++;
	}
	/* 计算当前树的左子树的结点个树 */
	int cnt = p - L1;
	lch[root] = build(L1, p - 1, L2, L2 + cnt - 1);
	rch[root] = build(p + 1, R1, L2 + cnt, R2 - 1);
	return root;
}

void DFS(int u, int sum)
{
	sum += u;
	/* 若当前是叶子结点 */
	if (!lch[u] && !rch[u])
	{
		/* 不仅要使权值和最小，还要尽量使叶子结点的权值也要小 */
		if (sum < best_sum || (sum == best_sum && u < best))
		{
			best = u;
			best_sum = sum;
		}
	}
	if (lch[u])
	{
		DFS(lch[u], sum);
	}
	if (rch[u])
	{
		DFS(rch[u], sum);
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	while (read_list(in_order))
	{
		read_list(post_order);
		build(0, n - 1, 0, n - 1);
		best_sum = 1000000;
		DFS(post_order[n - 1], 0);
		cout << "best = " << best << endl;
		cout << "best_sum = " << best_sum << endl;
	}
	system("pause");
	return 0;
}

