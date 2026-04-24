#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int visited[5001][5001];
int N;
queue<pair<pair<int, int>, int>>q;

int bfs(int x, int y)
{
	visited[x][y] = 1;
	int cnt = 0;
	q.push({ { x,y }, 0 });
	while (!q.empty())
	{
		x = q.front().first.first;
		y = q.front().first.second;
		cnt = q.front().second;
		visited[x][y] = 1;
		q.pop();
		if (y > 0)
		{
			if (!visited[x + y][y])
			{
				visited[x + y][y] = 1;
				q.push({ { x + y,y }, cnt + 1 });
				if (x + y == N)
					return cnt + 1;
			}
		}
		if (!visited[x][x])
		{
			visited[x][x] = 1;
			q.push({ {x,x},cnt + 1 });
		}
		if (x - 1 >= 0)
		{
			if (!visited[x - 1][y])
			{
				visited[x - 1][y] = 1;
				q.push({ {x - 1,y},cnt + 1 });
				if (x - 1 == N)
					return cnt + 1;
			}
		}
	}
}

int main(void)
{
	scanf("%d", &N);
	printf("%d\n",bfs(1, 0));
	return 0;
}