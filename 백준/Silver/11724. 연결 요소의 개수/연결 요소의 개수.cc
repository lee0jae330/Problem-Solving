#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<queue>

using namespace std;

#define MAX_INDEX 1002

int arr[MAX_INDEX][MAX_INDEX] = { 0, };
int visited[MAX_INDEX] = { 0, };


void dfs(int v, int N)
{
	visited[v] = 1;
	//printf("%d ", v);
	for (int i = 1; i <= N; i++)
	{
		if (visited[i] == 1 || arr[v][i] == 0)
			continue;
		dfs(i, N);
	}
}

int main(void)
{
	int N, M;
	scanf("%d %d", &N, &M);
	int v1, v2;
	int count = 0;
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &v1, &v2);
		arr[v1][v2] = 1;
		arr[v2][v1] = 1;
	}
	dfs(1, N);
	count++;
	for (int i = 2; i <= N; i++)
	{
		if (visited[i] == 0)
		{
			dfs(i, N);
			count++;
		}
	}
	printf("%d\n", count);
	return 0;
}