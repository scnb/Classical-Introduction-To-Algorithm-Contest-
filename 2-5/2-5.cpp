// 2-5.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int a, b, c;
	FILE *fin;
	if ((fin = fopen("Text.txt", "rb")) == NULL)
	{
		cout << "Error!" << endl;
		exit(1);
	}
	while (fscanf(fin, "%d %d %d", &a, &b, &c) == 3 && ((a != 0) && (b != 0) && (c != 0)))
	{
		double temp3 = (1.0)*a / b;
		printf("%.*lf\n", c , temp3);
	}
	getchar();
	return 0;
}

