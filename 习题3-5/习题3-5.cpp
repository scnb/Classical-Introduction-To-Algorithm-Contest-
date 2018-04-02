// 习题3-5.cpp : 定义控制台应用程序的入口点。
//谜题(Puzzle)
/* 这道题和之前做过的一道PAT乙级题目非常像，在这道题目中，并没有明确说明各种操作会不会超出范围，所以我默认
 * 各个操作都是不会超过范围的，也就没有判断边界条件。
*/

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ROW (5)
#define COL (5)
#define maxSize (10)

char table[ROW][COL];
char order[maxSize];

struct Empty
{
	int x = 0;	/* 行 */
	int y = 0;  /* 列 */
};

Empty empty;

void Display(char output[ROW][COL]);
void UP_op(char output[ROW][COL]);
void DOWN_op(char output[ROW][COL]);
void LEFT_op(char output[ROW][COL]);
void RIGHT_op(char output[ROW][COL]);

int _tmain(int argc, _TCHAR* argv[])
{
	
	FILE *fin;

	/* 为了输入简便，从文件中读入网格数据 */
	fin = fopen("input.txt", "rb");
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			int temp;
			fscanf(fin, "%c", &temp);
			table[i][j] = temp;
			if (table[i][j] == '+')
			{
				empty.x = i;
				empty.y = j;
			}
		}
	}
	printf("%d %d\n", empty.x, empty.y);
	/* 读入指令序列，以数字0结束 */
	scanf("%s", order);
	int len = strlen(order) - 1;
	/* 指示是否有错误的指令 */
	int bug = 0;
	for (int i = 0; i < len; i++)
	{
		switch (order[i])
		{
		case 'A':UP_op(table); break;
		case 'B':DOWN_op(table); break;
		case 'L':LEFT_op(table); break;
		case 'R':RIGHT_op(table); break;
		default: bug = 1; break;
		};
	}
	if (bug == 1)
	{
		printf("This puzzle has no final configuration!\n");
	}
	else
	{
		Display(table);
	}
	system("pause");
	return 0;
}

void Display(char output[ROW][COL])
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			printf("%c ", output[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void UP_op(char output[ROW][COL])
{
	char temp = output[empty.x][empty.y];
	output[empty.x][empty.y] = output[empty.x - 1][empty.y];
	output[empty.x - 1][empty.y] = temp;
	empty.x -= 1;
}

void DOWN_op(char output[ROW][COL])
{
	char temp = output[empty.x][empty.y];
	output[empty.x][empty.y] = output[empty.x + 1][empty.y];
	output[empty.x + 1][empty.y] = temp;
	empty.x += 1;
}

void LEFT_op(char output[ROW][COL])
{
	char temp = output[empty.x][empty.y];
	output[empty.x][empty.y] = output[empty.x][empty.y - 1];
	output[empty.x][empty.y - 1] = temp;
	empty.y -= 1;
}
void RIGHT_op(char output[ROW][COL])
{
	char temp = output[empty.x][empty.y];
	output[empty.x][empty.y] = output[empty.x][empty.y + 1];
	output[empty.x][empty.y + 1] = temp;
	empty.y += 1;
}