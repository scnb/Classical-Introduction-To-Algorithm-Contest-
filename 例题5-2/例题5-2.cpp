// 例题5-2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;

const int maxn = 30;
int n;

/* 定义一个数组，而数组中的每一个元素又是一个vector */
/* 所以pile可以看成一个二维数组，并且一维的大小是固定的，而二维的大小是可变的 */
vector<int> pile[maxn];

/* 找到木块a所在的堆，并找到木块a在该堆中的高度，并以引用的形式返回 */
void find_block(int a, int &p, int &h)
{
	for (p = 0; p < n; p++)
	{
		for (h = 0; h < pile[p].size(); h++)
		{
			if (pile[p][h] == a)
			{
				return;
			}
		}
	}
}

/* 把第p堆高度为h的木块上方的所有木块都移回原位 */
void clear_above(int p, int h)
{
	for (int i = h+1; i < pile[p].size(); i++)
	{
		int temp = pile[p][i];
		/* 将编号为temp的木块移回到第temp堆 */
		pile[temp].push_back(temp);
	}
	/* 调用resize方法，使第p堆只含有第0-（h-1）个木块 */
	pile[p].resize(h+1);
}

/* 把第p堆高度为h及其上方的木块都整体移动到p2堆上方 */
void pile_above(int p, int h, int p2)
{
	for (int i = h; i < pile[p].size(); i++)
	{
		pile[p2].push_back(pile[p][i]);
	}
	/* 调用resize方法，使第p堆只含有第0 - （h-2）个木块 */
	pile[p].resize(h);
}

void print()
{
	for (int i = 0; i < n; i++)
	{
		for (int h = 0; h < pile[i].size(); h++)
		{
			printf("%d ", pile[i][h]);
		}
		printf("\n");
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a, b;			//存储是哪个木块
	cin >> n;			//一共有n个木块
	string s1, s2;		//命令
	for (int i = 0; i < n; i++)
	{
		pile[i].push_back(i);
	}
	/* 使用cin能很方便的读取命令，并能自动把数据和字符串分开 */
	while (cin >> s1 >> a >> s2 >> b)
	{
		int p1, h1, p2, h2;
		find_block(a, p1, h1);
		find_block(b, p2, h2);
		if (p1 == p2)
		{
			printf("Wrong Command!\n");
			exit(-1);
		}
		/* 若是onto命令，则要把b木块上面的木块都拿掉 */
		if (s2 == "onto")
		{
			clear_above(p2, h2);
		}
		/* 若是move命令，则要把a木块上面的木块都拿掉 */
		if (s1 == "move")
		{
			clear_above(p1, h1);
		}
		/* 剩下就是把木块a及其上面的木块(可能已被拿走)都放在b木块所在堆的顶部(可能只剩b木块) */
		pile_above(p1, h1, p2);
		print();
	}
	
	return 0;
}

