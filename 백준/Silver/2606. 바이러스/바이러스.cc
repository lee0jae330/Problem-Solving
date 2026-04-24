#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int arr[101][101] = { 0, };
int visited[101] = { 0, };
int count = 0;

void dfs(int v, int N)
{
	visited[v] = 1;
	count++;
	for (int i = 1; i <= N; i++)
	{
		if (visited[i] == 1 || arr[v][i] == 0)
			continue;
		dfs(i, N);
	}
}

int main(void)
{
	int N;
	scanf("%d", &N);
	int M,v1,v2;
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &v1, &v2);
		arr[v1][v2] = 1;
		arr[v2][v1] = 1;
	}
	dfs(1, N);
	printf("%d\n", count-1);
	return 0;
}