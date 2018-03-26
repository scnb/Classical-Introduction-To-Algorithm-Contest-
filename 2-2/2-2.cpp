// 2-2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <stdio.h>

using namespace std;


int main(int argc, _TCHAR* argv[])
{
	int a, b, c;
	FILE *fin;
	if ((fin = fopen("Text.txt", "r"))==NULL)
	{
		cout << "Can't open file!" << endl;
		exit(1);
	}
	while (fscanf(fin, "%d %d %d", &a, &b, &c) == 3)
	{
		int flag = 0;
		for (int i = 10; i < 100; i++)
		{
			if (((i - a) % 3 == 0) && ((i - b) % 5 == 0) && ((i - c) % 7 == 0))
			{
				cout << i << endl;
				flag = 1;
			}
			if (flag == 1)
			{
				break;
			}
		}
		if (flag == 0)
		{
			cout << "No answer" << endl;
		}
	}
	Sleep(2000);
	return 0;
}

