// 例题6-3.cpp : 定义控制台应用程序的入口点。
//矩阵链乘(Matrix Chain Multiplication)：输入n个矩阵的维度和一些链乘表达式，判断能够进行乘法， 若能则输出乘法运算的次数。
/*	本题主要的工作就是解析表达式，可以用栈来完成该操作。
 *  注意：前提是输入的表达式形式上是正确的。只需要判断进行乘法运算的两个矩阵是否可以相乘即可。
 *  扫描表达式，遇到字母则入栈，遇到右括号则连续出栈两个元素进行运算，把运算结果再存入栈中。
*/

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <stack>
#include <string>
#include <vector>

using namespace std;

enum { A, B, C, D, E, F, G, H, I, J };

#define maxSize (10)

typedef struct matrix
{
	int row = 0;
	int col = 0;
}Matrix;

stack<Matrix> expr;

Matrix mat[maxSize];

int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int r, c;
		/* 输入该矩阵的维度 */
		scanf("%d %d", &r, &c);
		mat[A+i].row = r;
		mat[A+i].col = c;
	}
	/* 矩阵链乘表达式 */
	string str;
	Matrix A, B;
	while (cin >> str)
	{
		int sum = 0;
		int flag = 0;
		int len = str.length();
		for (int i = 0; i < len; i++)
		{
			if (isalpha(str[i]))
			{
				expr.push(mat[str[i]-'A']);
			}
			else if (str[i] == ')')
			{
				B = expr.top();
				expr.pop();
				A = expr.top();
				expr.pop();
				if (A.col == B.row)
				{
					Matrix temp;
					temp.row = A.row;
					temp.col = B.col;
					expr.push(temp);
					sum += A.row * A.col * B.col;
				}
				else
				{
					cout << "Error!\n";
					flag = 1;
					break;
				}
			}
		}
		if (flag != 1)
		{
			cout << "total multipication is:" << sum << endl;
		}
	}
	return 0;
}

