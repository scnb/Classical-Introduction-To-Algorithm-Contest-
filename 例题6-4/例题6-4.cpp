// 例题6-4.cpp : 定义控制台应用程序的入口点。
//破损的键盘（悲剧文本）：有一个破损的键盘，键盘上的所有键都可以正常工作，但是有时Home键或者End键会自动按下。
//任务是在打开显示器看到这个悲剧的文本之前，将这段文本计算出来（即显示器上将会显示什么内容）
/* 这道题的核心就是：Home键会让光标移动到行首，而End键使光标移动到行尾。所以在[和]之间的文本都会出现在行首。
 * 本题可以轻松使用链表来实现，因为涉及到了频繁的在文本之间进行移动，所以不能用数组，因为那样效率太低。
 * 读入一行文本之后，逐个字符的扫描， 如果是普通字符直接加到链表末尾，若是[，则将其后知道]之前的文本都加到链表首部
 * 处理完毕之后，输出即可。
*/

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>

using namespace std;

typedef struct node
{
	char c;
	struct node * next;
}Node;


int _tmain(int argc, _TCHAR* argv[])
{
	string s;
	ifstream fin("input.txt");
	while (getline(fin, s))
	{
		int len = s.length();
		/* str作为一个空结点 */
		Node *str = (Node *)malloc(sizeof(Node));
		Node *end = str;
		for (int i = 0; i < len; i++)
		{
			if (s[i] == '[')
			{
				i++;
				Node *cur = (Node *)malloc(sizeof(Node));
				if (cur == NULL)
				{
					cout << "Allocation Error!" << endl;
					exit(0);
				}
				cur = str->next;
				if (s[i] != ']')
				{
					Node *temp = (Node *)malloc(sizeof(Node));
					if (temp == NULL)
					{
						cout << "Allocation Error!" << endl;
						exit(0);
					}
					temp->c = s[i];
					temp->next = str->next;
					str->next = temp;
					cur = temp;
					i++;
				}
				
				/* 直到遇到]，否则都在链表头部插入 */
				while (s[i] != ']')
				{
					Node *temp = (Node *)malloc(sizeof(Node));
					if (temp == NULL)
					{
						cout << "Allocation Error!" << endl;
						exit(0);
					}
					temp->c = s[i];
					temp->next = cur->next;
					cur->next = temp;
					cur = temp;
					i++;
				}
			}
			/* 其实关于该字符的处理已经在上面完成了 */
			else if (s[i] == ']')
			{
			}
			else
			{
				Node *temp = (Node *)malloc(sizeof(Node));
				if (temp == NULL)
				{
					cout << "Allocation Error!" << endl;
					exit(0);
				}
				temp->c = s[i];
				temp->next = NULL;
				end->next = temp;
				end = temp;
			}
		}
		Node *start = str->next;
		for (start; start != NULL; start = start->next)
		{
			cout << start->c;
		}
		cout << endl;
	}
	system("pause");
	return 0;
}

