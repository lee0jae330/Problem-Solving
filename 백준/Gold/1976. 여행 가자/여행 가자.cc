#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<algorithm>

using namespace std;

int parent[201];
int level[201];

int find(int x)
{
	if (x == parent[x])
		return x;
	return parent[x] = find(parent[x]);
}

void merge(int x, int y)//x가 더 작은 트리
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
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
		level[i] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int num;
			scanf("%d", &num);
			if (num)
				merge(i, j);
		}
	}
	int check = 1;
	int num;
	scanf("%d", &num);
	int tmp = find(num);
	for (int i = 1; i < m; i++)
	{
		scanf("%d", &num);
		if (tmp != find(num))
			check = 0;
		if (!check)
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}