#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<memory.h>

int c[501];
int parent[501];
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
	int t = 1;
	while (1)
	{
		memset(c, 0, sizeof(c));
		int n, m,count=0;
		scanf("%d %d", &n, &m);
		if (n == 0 && m == 0)
			break;
		for (int i = 0; i <= n; i++)
			parent[i] = i;
		for (int i = 0; i < m; i++)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			int x = find(a);
			int y = find(b);
			merge(a, b);
			if (!check)
			{
				if(!c[find(a)])
					c[find(a)] = 1;
			}
			else
			{
				if (c[x] || c[y])
					c[x] = 1, c[y] = 1;
			}
		}
		/*for (int i = 1; i <= n; i++)
			printf("%d ", find(i));
		printf("\n");
		for (int i = 1; i <= n; i++)
			printf("%d ", c[i]);
		printf("\n");*/
		int tmp = find(1);
		int arr[501] = { 0, };
		for (int i = 1; i <= n; i++)
		{
			if (!c[find(i)])
			{
				if (!arr[find(i)])
				{
					count++;
					arr[find(i)] = 1;
				}
			}
		}
		printf("Case %d: ", t);
		if (count <= 0)
			printf("No trees.\n");
		else if (count == 1)
			printf("There is one tree.\n");
		else
			printf("A forest of %d trees.\n", count);
		t++;
	}
	return 0;
}