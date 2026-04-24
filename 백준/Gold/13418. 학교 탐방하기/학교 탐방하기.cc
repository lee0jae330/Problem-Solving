#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int parent[1001];
bool check;
int result1, result2;

vector<pair<int, pair<int, int>>>v1;
vector<pair<int, pair<int, int>>>v2;

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
	for (int i = 0; i < M+1; i++)
	{
		int a, b, cost;
		scanf("%d %d %d", &a, &b, &cost);
		v1.push_back({ cost,{a,b} });
		v2.push_back({ -cost,{a,b} });
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	for (int i = 0; i < v1.size(); i++)
	{
		merge(v1[i].second.first, v1[i].second.second);
		if (check)
		{
			if(!v1[i].first)
				result1++;
		}
	}
	init();
	for (int i = 0; i < v2.size(); i++)
	{
		merge(v2[i].second.first, v2[i].second.second);
		if (check)
		{
			if(!v2[i].first)
				result2++;
		}
	}
	printf("%d\n", result1 * result1 - result2 * result2);
	return 0;
}