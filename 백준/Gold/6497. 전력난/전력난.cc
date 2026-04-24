#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

int parent[200001];
bool check;
long long result = 0;

vector < pair<int, pair<int, int>>>v;


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
	while (1)
	{
		int m, n;
		scanf("%d %d", &m, &n);
		if (m == 0 && n == 0)
			return 0;
		v.clear();
		for (int i = 0; i < m; i++)
			parent[i] = i;
		long long sum = 0;
		for (int i = 0; i < n; i++)
		{
			int a, b, cost;
			scanf("%d %d %d", &a, &b, &cost);
			sum += cost;
			v.push_back({ cost,{a,b} });
		}
		sort(v.begin(), v.end());
		for (int i = 0; i < v.size(); i++)
		{
			merge(v[i].second.first, v[i].second.second);
			if (check)
				result += v[i].first;
		}
		printf("%lld\n", sum - result);
		result = 0;
	}
	return 0;
}