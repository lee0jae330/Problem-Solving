#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<algorithm>

using namespace std;

int parent[3001];

void init()
{
	for (int i = 0; i <= 3000; i++)
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
		if (x > y)
			parent[x] = y;
		else
			parent[y] = x;
	}
}

int ccw(pair<long long, long long >a, pair<long long, long long>b, pair<long long, long long>c) // s가 0보다 크면 반시계, 0보다 작으면 시계, 0이면 평행
{
	long long s = a.first * b.second + b.first * c.second + c.first * a.second;
	s -= a.first * c.second + b.first * a.second + c.first * b.second;
	if (s > 0)
		return 1;
	else if (s == 0)
		return 0;
	return -1;
}

int isIntersect(pair<pair<long long, long long>, pair<long long, long long>> x, pair<pair<long long, long long>, pair<long long, long long>> y) {
	pair<long long, long long> a = x.first;
	pair<long long, long long> b = x.second;
	pair<long long, long long> c = y.first;
	pair<long long, long long> d = y.second;
	int ab = ccw(a, b, c) * ccw(a, b, d);
	int cd = ccw(c, d, a) * ccw(c, d, b);
	if (ab == 0 && cd == 0) {
		if (a > b)swap(a, b);
		if (c > d)swap(c, d);
		return c <= b && a <= d;
	}
	return ab <= 0 && cd <= 0;
}



bool cmp(int a, int b)
{
	return a > b;
}

pair < pair<long long, long long>, pair<long long, long long>>line[3001];
int sol[3001];

int main(void)
{
	init();
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		long long a, b, c,d;
		scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
		line[i].first.first = a, line[i].first.second = b, line[i].second.first = c, line[i].second.second = d;
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = i + 1; j <= N; j++)
		{
			if (isIntersect(line[i], line[j]))
			{
				merge(i, j);
			}
		}
	}

	int tmp = 0;
	int MAX = 0;
	for (int i = 1; i <= N; i++)
	{
		if (!sol[find(i)])
		{
			tmp++;
			int cnt = 1;
			sol[find(i)] = 1;
			for (int j = i + 1; j <= N; j++)
			{
				if (find(i) == find(j))
					cnt++;
			}
			if (cnt > MAX)
				MAX = cnt;
		}
	}
	printf("%d\n", tmp);
	printf("%d\n", MAX);
}
