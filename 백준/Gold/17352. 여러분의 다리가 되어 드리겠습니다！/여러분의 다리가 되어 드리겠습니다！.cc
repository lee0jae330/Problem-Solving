#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<algorithm>

using namespace std;

int parent[300001];
int level[300001];

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
	if (x == y)
		return;
	if (level[x] > level[y])
		swap(x, y);
	parent[x] = y;
	if (level[x] == level[y])
		level[y]++;
}

int main(void)
{
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		parent[i] = i;
		level[i] = 1;
	}
	if (N == 2)
	{
		printf("1 2\n");
		return 0;
	}
	int std;
	for (int i = 1; i <= N - 2; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		if (i == 1)
			std = a;
		merge(a, b);
	}
	int check = 1;
	int num = find(std);
	for (int i = 1; i <= N; i++)
	{
		if (num != find(i))
		{
			printf("%d %d\n", std, i);
			return 0;
		}
	}
}