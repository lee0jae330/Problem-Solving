#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<queue>

using namespace std;

int arr[1002][1002] = { 0, };

int visited[1002] = { 0, };

void dfs(int v, int N) // v는 탐색할 정점, N은 정점 개수
{
	visited[v] = 1;
	printf("%d ", v);
	for (int i = 1; i <= N; i++)
	{
		if (visited[i] == 1 || arr[v][i] == 0)
			continue;
		dfs(i,N);
	}
}

void bfs(int v, int N)
{
	queue<int>q;
	visited[v] = 0;
	printf("%d ", v);
	q.push(v);
	while (!q.empty())
	{
		v = q.front();
		q.pop();
		for (int i = 1; i <= N; i++)
		{
			if (visited[i] == 0 || arr[v][i] == 0)
				continue;
			printf("%d ", i);
			q.push(i);
			visited[i] = 0;
		}
	}
}

int main(void)
{
	int N, M, V;
	int v1, v2;
	scanf("%d %d %d", &N, &M, &V);
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &v1, &v2);
		arr[v1][v2] = 1;
		arr[v2][v1] = 1;
	}
	dfs(V, N);
	printf("\n");
	bfs(V, N);
	printf("\n");
	return 0;
}