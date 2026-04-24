#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> node[100001];
int visited[100001] = { 0, };
int path[100001];

void dfs(int v)
{
	visited[v] = 1;	

	for (int i = 0; i < node[v].size(); i++)
	{
		if (visited[node[v][i]] == 1)
			continue;
		path[node[v][i]] = v;
		dfs(node[v][i]);
	}
}

int main(void)
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N-1; i++)
	{
		int  a, b;
		scanf("%d %d", &a, &b);
		node[a].push_back(b);
		node[b].push_back(a);
	}
	dfs(1);
	for (int i = 2; i <= N; i++)
		printf("%d\n", path[i]);

	return 0;
}