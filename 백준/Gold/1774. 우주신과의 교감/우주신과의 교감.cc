#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<math.h>
#include<stdlib.h>

using namespace std;

int parent[1001];
bool check;
double result = 0;
vector<pair<pair<long long, long long>, int>>xy;
vector < pair<long long, pair<int, int>>>v;

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
	for (int i = 0; i < N; i++)
	{
		long long x, y;
		scanf("%lld %lld", &x, &y);
		xy.push_back({ {x,y},i + 1 });
	}
	for (int i = 0; i < M; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		merge(a, b);
	}
	int num = N - 1 - M;
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			long long xx = xy[i].first.first - xy[j].first.first;
			long long yy = xy[i].first.second - xy[j].first.second;
			long long dist = xx * xx + yy * yy;
			v.push_back({ dist,{xy[i].second,xy[j].second} });
		}
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		merge(v[i].second.first, v[i].second.second);
		if (check)
		{
			result += sqrt(v[i].first);
		}
	}
	printf("%.2lf\n", result);
	return 0;
}