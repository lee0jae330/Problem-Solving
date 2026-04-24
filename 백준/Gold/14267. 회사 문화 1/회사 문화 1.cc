#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<memory.h>
#include<string.h>

using namespace std;

int score[100001];
int result[100001];
vector<int>v[100001];
int N, M;

void dfs(int x, int s)
{
	result[x] += s;
	for (int i = 0; i < v[x].size(); i++)
	{
		dfs(v[x][i], s);
	}
}

int main(void)
{
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)
	{
		int a;
		scanf("%d", &a);
		if (a == -1)
			continue;
		v[a].push_back(i);
	}
	for (int i = 0; i < M; i++)
	{
		int num, scr;
		scanf("%d %d", &num, &scr);
		score[num] += scr;
	}
	for (int i = 2; i <= N; i++)
	{
		if (score[i])
			dfs(i, score[i]);
	}
	for (int i = 1; i <= N; i++)
		printf("%d ", result[i]);
	return 0;
}