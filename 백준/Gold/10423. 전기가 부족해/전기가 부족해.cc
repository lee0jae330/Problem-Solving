#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

int parent[1001];
bool check;
int result;
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
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);
	int arr[1001];
	for (int i = 0; i < K; i++)
	{
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < K - 1; i++)
	{
		for (int j = i + 1; j < K; j++)
			merge(arr[i], arr[j]);
	}
	for (int i = 0; i < M; i++)
	{
		int a, b, cost;
		scanf("%d %d %d", &a, &b, &cost);
		v.push_back({ cost,{a,b} });
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		merge(v[i].second.first, v[i].second.second);
		if (check)
			result += v[i].first;
	}
	printf("%d\n ", result);
	return 0;
}