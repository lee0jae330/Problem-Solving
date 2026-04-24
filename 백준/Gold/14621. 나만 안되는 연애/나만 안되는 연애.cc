#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

int parent[1001];
bool check;
int result = 0;
char gender[1003];

vector<pair<int, pair<int, int>>>v;

void init()
{
	for (int i = 0; i < 1001; i++)
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
	init();
	int N, M;
	scanf("%d %d", &N, &M);
	getchar();
	for (int i = 0; i < N; i++)
	{
		scanf("%c", &gender[i]);
		getchar();
	}
	for (int i = 0; i < M; i++)
	{
		int a, b, cost;
		scanf("%d %d %d", &a, &b, &cost);
		if (gender[a - 1] != gender[b - 1])
		{
			v.push_back({ cost,{a,b} });
		}
	}
	sort(v.begin(), v.end());
	int num = 0;
	for (int i = 0; i < v.size(); i++)
	{
		merge(v[i].second.first, v[i].second.second);
		if (check)
		{
			num++;
			result += v[i].first;
		}
	}
	if (num == N - 1)
		printf("%d\n", result);
	else
		printf("-1\n");
	return 0;
}