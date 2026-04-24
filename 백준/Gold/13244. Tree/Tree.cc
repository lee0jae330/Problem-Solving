#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int parent[1001];
bool check;

int find(int x)
{
	if (x == parent[x])
		return x;
	return parent[x] = find(parent[x]);
}

void merge(int x, int y)
{
	x = find(x);
	y = find(y);
	check = false;
	if (x != y)
	{
		check = true;
		if (x < y)
			parent[y] = x;
		else
			parent[x] = y;
	}
}

int main(void)
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		int N;
		scanf("%d", &N);
		int M;
		scanf("%d", &M);
		int input = 0;
		for (int j = 0; j <= N; j++)
			parent[j] = j;
		for (int j = 0; j < M; j++)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			merge(a, b);
			if (!check)
				input = 1;
		}
		/*for (int j = 1; j <= N; j++)
			printf("%d ", find(j));
		printf("\n");*/
		if (input)
			printf("graph\n");
		else
		{
			int tmp = find(1);
			for (int j = 2; j <= N; j++)
			{
				if (tmp != find(j))
				{
					printf("graph\n");
					input = 1;
					break;
				}
			}
			if (!input)
				printf("tree\n");
		}
	}
	return 0;
}