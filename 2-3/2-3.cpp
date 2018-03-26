// 2-3.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	cin >> n;
	int N = 2 * n - 1;
	int k = 0;
	for (int i = n; n > 0; n--)
	{
		for (int j = 0; j < k; j++)
		{
			cout << " ";
		}
		for (int j = 0; j < N; j++)
		{
			cout << "*";
		}
		cout << endl;
		N = N - 2;
		k++;
	}
	getchar();
	getchar();
	return 0;
}

