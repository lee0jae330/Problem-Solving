#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<queue>


using namespace std;

vector<int>v[501];
int visited[501];

int cnt = 0;
queue<pair<int, int>>q;
void bfs(int x)
{
	visited[x] = 1;
	q.push({ x,0 });
	while (!q.empty())
	{
		x = q.front().first;
		int d = q.front().second;
		q.pop();
		for (int i = 0; i < v[x].size(); i++)
		{
			if (!visited[v[x][i]])
			{
				visited[v[x][i]] = 1;
				if (d + 1 > 2)
					continue;
				cnt++;
				q.push({ v[x][i],d + 1 });
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

	printf("%d\n", cnt);
	return 0;
}