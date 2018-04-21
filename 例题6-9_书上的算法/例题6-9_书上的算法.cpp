// 例题6-9_书上的算法.cpp : 定义控制台应用程序的入口点。
//本程序为书上的算法，思路与我的算法是一样的，都是用递归接收输入的过程中判断子树是否平衡。
//但是书上的算法在处理return true方面做得很好。
//另外，在if判断部分也更简洁。

#include "stdafx.h"
#include <iostream>

using namespace std;

bool solve(int &w)
{
	int wl, dl, wr, dr;
	bool a = true, b = true;
	cin >> wl >> dl >> wr >> dr;
	if (!wl)
	{
		a = solve(wl);
	}
	if (!wr)
	{
		b = solve(wr);
	}
	w = wl + wr;
	return a && b && (wl*dl == wr*dr);
}

int main()
{
	int w = 0;
	if (solve(w))
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
	system("pause");
    return 0;
}

