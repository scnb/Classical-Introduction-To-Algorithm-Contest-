// 例题5-8.cpp : 定义控制台应用程序的入口点。
//Unix is 命令
/* 输入正整数n以及n个文件名，排序后按列优先的方式左对齐输出。
 * 假定最长文件名有M个字符，则最右列有M个字符，其他列都是M+2字符。
 */

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;

vector<string> file;

int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	int M = 0;
	int len = 0;
	string temp;
	ifstream fin("input.txt");
	/* 读入文件个数 */
	cin >> n;
	/* 读入文件名并计算最大的文件名长度 */
	while (getline(fin,temp))
	{
		len = temp.length();
		if (len > M)
		{
			M = len;
		}
		file.push_back(temp);
	}
	/* 对文件名进行排序 */
	sort(file.begin(), file.end());

	/* 对文件名进行填充，使最后一列有M个字符，其他列有M+2个字符 */
	for (int i = 0;i < n;i++)
	{
		/* 计算出要填充的位数 */
		int add = M - file[i].length();
		if ((i + 1) % 5 == 0)
		{
			for (int k = 0;k < add;k++)
			{
				file[i] += ' ';
			}
		}
		else
		{
			add += 2;
			for (int k = 0;k < add;k++)
			{ 
				file[i] += ' ';
			}
		}
	}

	/* 1行输出5个文件名 */
	int cnt = 5;
	int row;
	if (n%cnt == 0)
	{
		row = n / cnt;
	}
	else
	{
		row = n / cnt + 1;
	}
	int base = 5;
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{	
		if (n - i*cnt < cnt)
		{
			cnt = n - i*cnt;
		}
		for (j = 0; j < cnt; j++)
		{
			printf("%s", file[i * base + j].c_str());
		}
		cout << endl;
	}
	system("pause");
	return 0;
}

