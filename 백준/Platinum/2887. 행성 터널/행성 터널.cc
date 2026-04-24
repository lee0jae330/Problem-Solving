#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<stdlib.h>

using namespace std;

int parent[100001];
bool check = true;
long long result = 0;
vector<pair<int,int>>X;
vector<pair<int, int>>Y;
vector<pair<int, int>>Z;

vector<pair<int, pair<int, int>>>v;

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
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		X.push_back({ a,i }), Y.push_back({ b,i }), Z.push_back({ c,i });
	}
	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());
	sort(Z.begin(), Z.end());
	for (int i = 0; i < N - 1; i++)
	{
		int x = abs(X[i].first - X[i + 1].first);
		int y = abs(Y[i].first - Y[i + 1].first);
		int z = abs(Z[i].first - Z[i + 1].first);
		v.push_back({ x,{X[i].second,X[i+1].second} });
		v.push_back({ y,{Y[i].second,Y[i + 1].second} });
		v.push_back({ z,{Z[i].second,Z[i + 1].second} });
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < 3*(N-1); i++)
	{
		merge(v[i].second.first, v[i].second.second);
		if (check)
			result += v[i].first;
	}
	printf("%lld\n", result);
	return 0;
}