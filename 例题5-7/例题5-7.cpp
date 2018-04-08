// 例题5-7.cpp : 定义控制台应用程序的入口点。
//丑数(Ugly number)；丑数是指不能被2,3,5以外的其他素数整除的数。
/* 本例主要讲解优先队列的使用：优先队列，出队的元素不是队首的元素，而是优先级最高的元素，
 * 默认，越大的元素优先级越过，但是也可以通过在定义时指定，来使越小的元素优先级越高。
 * 思路：数x是丑数，则2x，3x，5x也都是丑数，所以可以通过最小的丑数1来生成所有的丑数。
 * 每次从优先队列中取出最小的数，然后分别乘以3个系数，判断不重复后，再存入优先队列中，
 * 重复这一过程直到第1500次循环。
 * 这种思路很高效，相对于从1往上循环，判断每个数是不是丑数。
*/

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <set>
#include <queue>
#include <functional>

using namespace std;

typedef long long LL;
/* 系数数组 */
const int coeff[3] = { 2, 3, 5 };


int _tmain(int argc, _TCHAR* argv[])
{
	/* 传入比较函数greater，指定元素小的优先级大 */
	priority_queue<LL, vector<LL>, greater<LL> > pq;
	set<LL> s;
	pq.push(1);
	s.insert(1);
	for (int i = 1;; i++)
	{
		LL x = pq.top();
		pq.pop();
		if (i == 1500)
		{
			cout << "The 1500'th ugly number is :" << x << endl;
		}
		for (int j = 0; j < 3; j++)
		{
			LL x2 = x*coeff[j];
			/* 检测x2是不是重复出现 */
			if (!s.count(x2))
			{
				s.insert(x2);
				pq.push(x2);
			}
		}
	}
	system("pause");
	return 0;
}

