#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>

using namespace std;

int parent[100001];

void init()
{
	for (int i = 0; i < 100001; i++)
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
	if (x != y)
	{
		if (x < y)
			parent[y] = x;
		else
			parent[x] = y;
	}
}

int main(void)
{
	init();
	int N, result = 0, input = 1;
	scanf("%d", &N);
	int M;
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		int num;
		scanf("%d", &num);
		if (input&&find(num) != 0)
		{
			result++;
			if (parent[num] - 1)
				merge(num, parent[num] - 1);
			else
				merge(num, 0);
		}
		else
		{
			input = 0;
			continue;
		}
	}
	printf("%d\n", result);
	return 0;
}