// 例题6-10.cpp : 定义控制台应用程序的入口点。
//下落的树叶（The falling leaves）：给一棵二叉树，每一个节点都有一个水平位置，左子节点
//在它左边1个单位，右字节点在它右边一个单位。从左向右输出每个水平位置的所有节点的权值之和

#include "stdafx.h"
#include <iostream>

using namespace std;

/* 尽量把数组开的大一点， 防止树特别倾斜 */
const int maxn = 100;

int sum[maxn];

void build(int p)
{
	int v;
	cin >> v;
	if (v == -1)
	{
		return;
	}
	sum[p] += v;	//p位置上增加一个值
	build(p - 1);	//先处理左子树，即往左一格
	build(p + 1);	//再处理右子树，即往右一格
}

bool init()
{
	int v;
	cin >> v;
	if (v == -1)
	{
		return false;
	}
	/* 一定要在一次输入前清0，否则会导致第一次输入以后的统计出现问题 */
	memset(sum, 0, sizeof(sum));
	int pos = maxn / 2;
	sum[pos] = v;			//存入根结点
	build(pos - 1);
	build(pos + 1);
	/* 别忘了return true，否则编译不通过 */
	return true;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int kase = 0;
	while (init())
	{
		int p = 0;
		while (sum[p] == 0)
		{
			p++;
		}
		cout << "Case " << ++kase << ":\n" << sum[p];
		while (sum[++p] != 0)
		{
			cout << " " << sum[p];
		}
		cout << endl;
	}
	system("pause");
	return 0;
}

