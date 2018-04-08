// 例5-5.cpp : 定义控制台应用程序的入口点。
//集合栈计算机：这个题的题干有点迷，不过还是能看懂。只是用的数据元素有点不常见——集合的集合
//本例主要讲解栈的使用
//以下代码是书上的代码

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <stack>
#include <string>
#include <set>
#include <map>
#include <vector>

using namespace std;

#define ALL(x) x.begin(), x.end()
#define INS(x) inserter(x,x.begin())

typedef set<int> Set;
map<Set, int>IDcache;			//根据集合取出其ID
vector<Set> Setcache;			//根据ID的集合取出该集合


/* 查找给定集合的ID， 若找不到，则分配一个新ID */
int ID(Set x)
{
	if (IDcache.count(x))
	{
		return IDcache[x];
	}
	Setcache.push_back(x);
	return IDcache[x] = Setcache.size() - 1;
}

int _tmain(int argc, _TCHAR* argv[])
{
	/* 栈里边存的是集合的ID */
	stack<int> s;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string op;
		cin >> op;
		if (op[0] == 'P')
		{
			s.push(ID(Set()));
		}
		else if (op[0] == 'D')
		{
			s.push(s.top());
		}
		else
		{
			/* 以下操作的共同点是都要先出栈两个栈顶元素 */
			Set x1 = Setcache[s.top()];
			s.pop();
			Set x2 = Setcache[s.top()];
			s.pop();
			Set x;
			/* Union：出栈两个集合，将其并集入栈 */
			if (op[0] == 'U')
			{
				set_union(ALL(x1), ALL(x2), INS(x));
			}
			/* Insersection：出栈两个集合，将其交集入栈 */
			else if (op[0] == 'I')
			{
				set_intersection(ALL(x1), ALL(x2), INS(x));
			}
			/* Add：出栈两个集合，将先出栈的集合加入到后出栈的集合中 */
			else if (op[0] == 'A')
			{
				x = x2;
				x.insert(ID(x1));
			}
			s.push(ID(x));
		}
		cout << Setcache[s.top()].size() << endl;
	}
	return 0;
}

