#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>

using namespace std;

vector<int>v[51];
int path[51];
int visited[51] = { 0, };
int cnt = 0;
int sol = 0;

void dfs(int x)
{
	visited[x] = 1;
	if (v[x].size()==0)
	{
		cnt++;
		return;
	}
	for (int i = 0; i < v[x].size(); i++)
	{
		if (visited[v[x][i]])
			continue;
		dfs(v[x][i]);
	}
}

void dfs2(int x)
{
	visited[x] = 0;
	if (v[x].size() == 0)
	{
		sol++;
		return;
	}
	for (int i = 0; i < v[x].size(); i++)
	{
		if (!visited[v[x][i]])
			continue;
		dfs2(v[x][i]);
	}
}



int main(void)
{
	int N, data;
	scanf("%d", &N);
	int tmp;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &data);
		if (data == -1)
		{
			tmp = i;
			continue;
		}
		v[data].push_back(i);
		path[i] = data;
	}
	dfs(tmp);
	int del;
	scanf("%d", &del);
	dfs2(del);
	if (cnt == sol && tmp != del)
	{
		printf("1\n");
		return 0;
	}
	int result = cnt - sol;
	if (cnt!=1&&path[del] != tmp&&v[path[del]].size()==1)
		result++;
	printf("%d\n", result);
	return 0;
}