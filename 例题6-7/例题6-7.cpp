// 例题6-7.cpp : 定义控制台应用程序的入口点。
//二叉树的层次遍历（Trees on the level）
//输入一棵二叉树，按从上到下，从左到右的顺序输出各个结点的值。
//每个结点按照从根节点到它的移动序列给出，如：(5,LL)表示，该结点的值是5，从根结点两次向左到达该结点。
//在输入中，每个结点的左右括号之间没有空格。相邻结点之间用一个空格隔开。
//每棵树的输入用一对括号"()"结束。

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstdlib>

using namespace std;

#define maxn (256)

char s[maxn];

/* 结点结构体 */
struct Node
{
	bool have_value;	//记录是否被赋值过
	int v;
	Node *left, *right;
	Node() :have_value(false), left(NULL), right(NULL) {}	//构造函数
};

Node *root;				//根结点
bool failed = false;	//标记输入中是否有错误的结点信息

/* 创建新结点 */
Node *newnode()
{
	return new Node();
}

/* 在二叉树中添加结点 */
void addnode(int v, char *s)
{
	int len = strlen(s);
	Node *u = root;
	/* 根据移动序列找到该结点的位置 */
	for (int i = 0; i < len; i++)
	{
		/* 向左走 */
		if (s[i] == 'L')
		{
			/* 若左子树不存在，则创建左子树的根结点 */
			if (u->left == NULL)
			{
				u->left = newnode();
			}
			u = u->left;
		}
		else if (s[i] == 'R')
		{
			/* 若右子树不存在，则创建右子树的根结点 */
			if (u->right == NULL)
			{
				u->right = newnode();
			}
			u = u->right;
		}
	}
	/* 检查是否重复赋值 */
	if (u->have_value == true)
	{
		failed = true;
	}
	u->v = v;
	/* 标记该结点已被赋过值 */
	u->have_value = true;

}

/* 读入二叉树的各个结点 */
bool read_input()
{
	failed = false;
	root = newnode();
	FILE *fin = fopen("input.txt", "rb");
	for (;;)
	{
		if (fscanf(fin, "%s", s) != 1)
		{
			return false;
		}
		if (!strcmp(s, "()"))
		{
			break;
		}
		int v;
		/* s[1]是一个字符串，从s字符串中的下标为1的字符开始，到'\0'结束 */
		sscanf(&s[1], "%d", &v);
		/* strchr()函数返回s字符串中第一个','字符的指针 */
		addnode(v, strchr(s, ',') + 1);
	}
	return true;
}

/* 使用宽度优先遍历来对二叉树进行层次遍历 */
bool BFS(vector<int>& ans)		//vector用来存输出的结点值
{
	/* 借用一个队列来进行层次遍历 */
	queue<Node *>q;
	ans.clear();
	q.push(root);
	while (!q.empty())
	{
		Node *u = q.front();
		q.pop();
		if (!u->have_value)
		{
			return false;
		}
		ans.push_back(u->v);
		/* 若当前结点的左、右子树不为空，则将其入队 */
		if (u->left != NULL)
		{
			q.push(u->left);
		}
		if (u->right != NULL)
		{
			q.push(u->right);
		}
	}
	return true;
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> ans;
	/* 如果输入中结点信息有问题，则输出-1 */
	read_input();
	if (failed)
	{
		cout << -1 << endl;
		system("pause");
		return 0;
	}
	BFS(ans);
	int size = ans.size();

	for (int i = 0; i < size; i++)
	{
		cout << ans[i] << " ";
	}
	system("pause");
	return 0;
}

