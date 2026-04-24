#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

int parent[500001];
bool check;

void init()
{
	for (int i = 0; i < 500001; i++)
		parent[i] = i;
}

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
	int result = 0;
	int input = 0;
	init();
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		merge(a, b);
		if (!check && !input)
		{
			result = i + 1;
			input = 1;
		}
	}
	printf("%d\n",result);
	return 0;
}