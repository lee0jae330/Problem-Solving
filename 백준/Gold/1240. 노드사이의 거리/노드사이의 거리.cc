#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

vector<pair<int, int>>v[1001];
int visited[1001];
int dist[1001];
void dfs(int start)
{
	visited[start] = 1;
	for (int i = 0; i < v[start].size(); i++)
	{
		if (visited[v[start][i].first])
			continue;
		dist[v[start][i].first] += v[start][i].second+dist[start];
		dfs(v[start][i].first);
	}
}

int main(void)
{
	int N, M;
	int a, b, atob;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N - 1; i++)
	{
		scanf("%d %d %d", &a, &b, &atob);
		v[a].push_back({ b,atob });
		v[b].push_back({ a,atob });
	}
	int x, y;
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &x, &y);
		dfs(x);
		printf("%d\n", dist[y]);
		for (int j = 0; j <= N; j++)
		{
			visited[j] = 0;
			dist[j] = 0;
		}
	}
	return 0;
}