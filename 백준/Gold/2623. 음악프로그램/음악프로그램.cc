#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

queue<int>q;
int degree[1001];
vector<int>v[1001];
int N, M;

void topicalsort()
{
	vector<int>sol;
	for (int i = 1; i <= N; i++)
	{
		if (degree[i] == 0)
			q.push(i);
	}
	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		sol.push_back(x);
		for (int j = 0; j < v[x].size(); j++)
		{
			int y = v[x][j];
			if (--degree[y] == 0)
				q.push(y);
		}
	}
	if (sol.size() != N)
		printf("0\n");
	else
	{
		for (int i = 0; i < sol.size(); i++)
			printf("%d\n", sol[i]);
	}
}

int main(void)
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++)
	{
		vector<int>vt;
		int num;
		scanf("%d", &num);
		for (int j = 0; j < num; j++)
		{
			int a;
			scanf("%d", &a);
			vt.push_back(a);
		}
		for (int j = 0; j < num - 1; j++)
		{
			v[vt[j]].push_back(vt[j + 1]);
			degree[vt[j + 1]]++;
		}
	}
	topicalsort();
	return 0;
}
