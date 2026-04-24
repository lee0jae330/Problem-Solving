#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

int parent[52];
vector<int>v[52];

void init()
{
	for (int i = 0; i < 52; i++)
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
	int N, M;
	scanf("%d %d", &N, &M);
	int num,sol=M;
	scanf("%d", &num);
	if (num > 0)
	{
		for (int i = 0; i < num; i++)
		{
			int tmp;
			scanf("%d", &tmp);
			merge(0, tmp);
		}
	}
	for (int i = 0; i < M; i++)
	{
		int team;
		scanf("%d", &team);
		for (int j = 0; j < team; j++)
		{
			int tmp;
			scanf("%d", &tmp);
			v[i].push_back(tmp);
		}
		for (int j = 0; j < v[i].size(); j++)
		{
			for (int k = j + 1; k < v[i].size(); k++)
			{
				merge(v[i][j], v[i][k]);
			}
		}
	}
	for (int i = 0; i < M; i++)
	{
		if (find(v[i][0]) == 0)
			sol--;
	}
	printf("%d\n", sol);
	return 0;
}