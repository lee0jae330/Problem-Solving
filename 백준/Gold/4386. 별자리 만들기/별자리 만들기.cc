#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

int parent[102];
bool check = true;
vector<pair<double, double>>xy;
vector<pair<double, pair<int,int>>>v;
double result = 0;

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
	return;
}

int main(void)
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i <= N; i++)
	{
		parent[i] = i;
	}
	for (int i = 0; i < N; i++)
	{
		double x, y;
		scanf("%lf %lf", &x, &y);
		xy.push_back({ x,y });
	}
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			double x1 = xy[i].first - xy[j].first;
			double y1 = xy[i].second - xy[j].second;
			double dist = sqrt(pow(x1, 2) + pow(y1, 2));
			v.push_back({ dist,{i,j} });
		}
	}
	sort(v.begin(), v.end());
	int num = N * (N - 1) / 2;
	for (int i = 0; i < num; i++)
	{
		merge(v[i].second.first, v[i].second.second);
		if (check)
			result += v[i].first;
	}
	printf("%.2lf\n", result);
	return 0;
}