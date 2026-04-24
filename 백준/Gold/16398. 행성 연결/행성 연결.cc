#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

int parent[1001];
bool check;
long long result = 0;

int arr[1001][1001];
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
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &arr[i][j]);
			if (i < j)
				v.push_back({ arr[i][j],{i,j} });
		}
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		merge(v[i].second.first, v[i].second.second);
		if (check)
			result += v[i].first;
	}
	printf("%lld\n", result);
	return 0;
}