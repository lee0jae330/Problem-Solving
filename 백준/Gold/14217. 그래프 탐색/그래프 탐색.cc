#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<memory.h>
#include<string.h>

using namespace std;

vector<int>v[501];
int visited[501];
int dist[501];
int a, p, q;
queue<int>qu;

void bfs(int x)
{
	visited[x] = 1;
	qu.push(x);
	dist[x] = 0;
	while (!qu.empty())
	{
		x = qu.front();
		int d = dist[x];
		qu.pop();
		for (int i = 0; i < v[x].size(); i++)
		{
			if (!visited[v[x][i]])
			{
				dist[v[x][i]] = d + 1;
				visited[v[x][i]] = 1;
				qu.push(v[x][i]);
			}
		}
	}
}
int main(void)
{
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}

	int T;
	scanf("%d", &T);
	for (int x = 0; x < T; x++)
	{
		memset(visited, 0, sizeof(visited));
		memset(dist, -1, sizeof(dist));
		scanf("%d %d %d", &a, &p, &q);
		if (a == 1)
		{
			v[p].push_back(q);
			v[q].push_back(p);
		}
		else
		{
			auto it = find(v[p].begin(), v[p].end(), q);
			v[p].erase(it);
			it = find(v[q].begin(), v[q].end(), p);
			v[q].erase(it);
		}
		bfs(1);
		for (int i = 1; i <= N; i++)
			printf("%d ", dist[i]);
		printf("\n");
	}
	return 0;
}