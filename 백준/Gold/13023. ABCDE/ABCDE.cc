#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<memory.h>
#include<string.h>

using namespace std;

vector<int>v[2001];
int visited[2001];
int N, M;
int depth = 0;
int input = 0;
void dfs(int x)
{
	visited[x] = 1;
	if (depth == 4)
	{
		input = 1;
		return;
	}
	for (int i = 0; i < v[x].size(); i++)
	{
		if (!visited[v[x][i]])
		{
			depth++;
			dfs(v[x][i]);
			visited[v[x][i]] = 0;
			depth--;
		}
	}
}
int main(void)
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= N; i++)
	{
		memset(visited, 0, sizeof(visited));
		input = 0;
		depth = 0;
		dfs(i);
		if (input == 1)
		{
			printf("1\n");
			return 0;
		}
	}
	printf("0\n");
	return 0;
}