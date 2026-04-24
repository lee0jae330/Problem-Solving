#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<queue>

using namespace std;

typedef struct TREE* tree;

typedef struct TREE {
	char name;
	tree lchild, rchild;
}TR;


tree levelSearching(tree ptr, char target)
{
	if (!ptr)
		return NULL;
	queue<tree>q;
	q.push(ptr);
	while (1)
	{
		ptr = q.front();
		q.pop();
		if (!ptr)
			return NULL;
		if (ptr->name == target)
			return ptr;
		if (ptr)
		{
			if (ptr->lchild)
				q.push(ptr->lchild);
			if (ptr->rchild)
				q.push(ptr->rchild);
		}
		else
			break;
	}
	return NULL;
}

void preorder(tree ptr)
{
	if (ptr)
	{
		printf("%c", ptr->name);
		preorder(ptr->lchild);
		preorder(ptr->rchild);
	}
}

void inorder(tree ptr)
{
	if (ptr)
	{
		inorder(ptr->lchild);
		printf("%c", ptr->name);
		inorder(ptr->rchild);
	}
}

void postorder(tree ptr)
{
	if (ptr)
	{
		postorder(ptr->lchild);
		postorder(ptr->rchild);
		printf("%c", ptr->name);
	}
}
tree Tree = NULL;

int main(void)
{
	
	int N;
	char root, l, r;
	scanf("%d", &N);
	getchar();
	for (int i = 0; i < N; i++)
	{
		scanf("%c", &root);
		getchar();
		scanf("%c", &l);
		getchar();
		scanf("%c", &r);
		getchar();
		if (Tree == NULL)
		{
			tree head = (tree)malloc(sizeof(*head));
			head->name = root;
			if (l == '.' &&r=='.')
			{
				head->lchild = NULL, head->rchild = NULL;
			}
			else if (l == '.')
			{
				tree tmp = (tree)malloc(sizeof(*tmp));
				tmp->name = r;
				tmp->lchild = NULL, tmp->rchild = NULL;
				head->rchild = tmp;
				head->lchild = NULL;
			}
			else if (r == '.')
			{
				tree tmp = (tree)malloc(sizeof(*tmp));
				tmp->name = l;
				tmp->lchild = NULL, tmp->rchild = NULL;
				head->lchild = tmp;
				head->rchild = NULL;
			}
			else
			{
				tree tmp1, tmp2;
				tmp1 = (tree)malloc(sizeof(*tmp1));
				tmp2 = (tree)malloc(sizeof(*tmp2));

				tmp1->name = l, tmp1->lchild = NULL, tmp1->rchild = NULL;
				tmp2->name = r, tmp2->lchild = NULL, tmp2->rchild = NULL;

				head->lchild = tmp1, head->rchild = tmp2;
			}
			Tree = head;
		}
		else
		{
			tree head = levelSearching(Tree, root);
			if (l == '.' && r == '.')
			{
				head->lchild = NULL, head->rchild = NULL;
			}
			else if (l == '.')
			{
				tree tmp = (tree)malloc(sizeof(*tmp));
				tmp->name = r;
				tmp->lchild = NULL, tmp->rchild = NULL;
				head->rchild = tmp;
				head->lchild = NULL;
			}
			else if (r == '.')
			{
				tree tmp = (tree)malloc(sizeof(*tmp));
				tmp->name = l;
				tmp->lchild = NULL, tmp->rchild = NULL;
				head->lchild = tmp;
				head->rchild = NULL;
			}
			else
			{
				tree tmp1, tmp2;
				tmp1 = (tree)malloc(sizeof(*tmp1));
				tmp2 = (tree)malloc(sizeof(*tmp2));

				tmp1->name = l, tmp1->lchild = NULL, tmp1->rchild = NULL;
				tmp2->name = r, tmp2->lchild = NULL, tmp2->rchild = NULL;

				head->lchild = tmp1, head->rchild = tmp2;
			}
		}
	}
	preorder(Tree);
	printf("\n");
	inorder(Tree);
	printf("\n");
	postorder(Tree);
	printf("\n");
	return 0;
}