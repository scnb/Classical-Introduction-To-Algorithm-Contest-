// 例题6-9.cpp : 定义控制台应用程序的入口点。
//天平（Not so Mobile）：输入一个树状天平， 根据力矩相等原则判断是否平衡。所谓力矩相等， 就是Wl*Dl = Wr*Dr，wl和dl分别是
//左右两边砝码的重量，D为距离。
//采用递归的方式输入， 每个天平的格式为Wl，Dl， Wr，Dr， 当Wl或Wr为0时， 表示该砝码实际是一个子天平， 接下来会描述这个子天平。
//当Wl=Wr=0时，会先描述左子天平，再描述右子天平。

/* 思路：递归接收输入，并进行判断， 一边接收输入，一边就能判断是否平衡。
	先判断左子树，再右子树，再把左、右子树的重量相加赋给上一层结点。
*/

/* 第一版的程序是有BUG的， 再递归程序solve中，我并没有写return true；
 * 但是运行结果依然正确， 这是因为在递归程序的最后，返回的是最后求得的
 * 最上层的天平的重量和，一般这个重量不为0， 所以相当于true。
 * 其实这也不太算BUG，因为我们默认输入不会全都是0 dl 0 dr这种形式，否则无法计算
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

/* 使用引用的方式传值，可以方便的将子树的重量相加赋给上一层的天平 */
bool solve(int &w)
{
	int wl, dl, wr, dr;
	scanf("%d %d %d %d", &wl, &dl, &wr, &dr);
	/* 若都为0，表示左右都是子天平， 则先左后右 */
	if (wl == 0 && wr == 0)
	{
		solve(wl);
		solve(wr);
	}
	else if (wl == 0 && wr != 0)
	{
		solve(wl);
	}
	else if (wl != 0 && wr == 0)
	{
		solve(wr);
	}
	/* 判断力矩是否相等 */
	if (wl*dl != wr*dr)
	{
		return false;
	}
	else
	{
		/* 将子树的重量相加 */
		w = wl + wr;
	}	
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

