// 例题5-3.cpp : 定义控制台应用程序的入口点。
//安迪的第一个字典：输入一个文本，从中找出所有不同的单词（不区分大小写），按照字典序从小到大排序。
/*
 * 本例只要是用于说明set（集合）的用法
 */

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <set>
#include <string>
#include <sstream>

using namespace std;

/* 创建一个集合，集合中的每个元素是一个string */
set<string> dict;


int _tmain(int argc, _TCHAR* argv[])
{
	string s, buf;
	while (cin >> s)
	{
		/* 一次只读入一个字符串 */
		for (int i = 0; i < s.length(); i++)
		{
			/* 将字符串都转换成小写字母，并且不是把非字母的字符变成空格 */
			/* isalpha函数用来判断是不是字母 */
			if (isalpha(s[i]))
			{
				s[i] = tolower(s[i]);
			}
			else
			{
				s[i] = ' ';
			}
		}
	 	stringstream ss(s);
		/* 把字符串读入到buf中 */
		while (ss >> buf)
		{
			dict.insert(buf);
		}
	}
	for (set<string>::iterator it = dict.begin(); it != dict.end(); it++)
	{
		cout << *it << endl;
	}
	system("pause");
	return 0;
}

