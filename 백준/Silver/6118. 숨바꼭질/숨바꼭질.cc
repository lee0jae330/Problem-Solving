#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

vector<int>v[20002];
int visited[20002] = { 0, };
int dist[20002] = { 0, };
int copy_dist[20002] = { 0, };
queue<int>q;
int index = 0;
void bfs(int x)
{
	q.push(x);
	visited[x] = 1;
	while (!q.empty())
	{
		int x = q.front();
		int dis = dist[x];
		q.pop();
		for (int i = 0; i < v[x].size(); i++)
		{
			if (!visited[v[x][i]])
			{
				q.push(v[x][i]);
				visited[v[x][i]] = 1;
				int tmp = dis - 1;
				dist[v[x][i]] = tmp;
				copy_dist[v[x][i]] = tmp;
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
	bfs(1);
	sort(dist, dist + N+1);
	for (int i = 1; i <= N; i++)
	{
		if (dist[0] == copy_dist[i])
		{
			printf("%d ", i);
			break;
		}
	}
	printf("%d ", -dist[0]);
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		if (dist[0] == dist[i])
			count++;
		else
			break;
	}
	printf("%d\n", count);
	return 0;
}