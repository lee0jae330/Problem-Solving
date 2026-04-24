#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

priority_queue<int>q;
int degree[32001];
vector<int>v[32001];
int N, M;

void topicalsort()
{
	vector<int>sol;
	for (int i = 1; i <= N; i++)
	{
		if (degree[i] == 0)
			q.push(-i);
	}
	while(!q.empty())
	{
		int x = -q.top();
		q.pop();
		printf("%d ", x);
		for (int j = 0; j < v[x].size(); j++)
		{
			int y = v[x][j];
			if (--degree[y] == 0)
				q.push(-y);
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
		degree[b]++;
	}
	topicalsort();
	return 0;
}
