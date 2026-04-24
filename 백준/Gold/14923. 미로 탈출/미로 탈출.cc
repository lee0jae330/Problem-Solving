#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<queue>

using namespace std;

int N, M;
int arr[1001][1001];
int visited[1001][1001][2];
int xx[4] = { -1,0,1,0 };
int yy[4] = { 0,1,0,-1 };
int sx, sy;
int ex, ey;
queue<pair<pair<int, int>,int>>q;

int bfs(int x, int y)
{
	visited[x][y][0] = 1;
	q.push({{ x,y }, 0});
	while (!q.empty())
	{
		x = q.front().first.first;
		y = q.front().first.second;
		int wall = q.front().second;
		q.pop();
		if (x == ex && y == ey)
			return visited[x][y][wall];
		for (int i = 0; i < 4; i++)
		{
			int tx = x + xx[i];
			int ty = y + yy[i];
			if (tx >= 0 && ty >= 0 && tx < N && ty < M)
			{
				if (arr[tx][ty] == 1 && wall == 0)
				{
					visited[tx][ty][wall + 1] = visited[x][y][wall] + 1;
					q.push({ {tx,ty},1 });
				}
				if (!arr[tx][ty] && !visited[tx][ty][wall])
				{
					visited[tx][ty][wall] = visited[x][y][wall] + 1;
					q.push({ {tx,ty},wall });
				}
			}
		}
	}
	return -1;
}

int main(void)
{
	scanf("%d %d", &N, &M);
	scanf("%d %d", &sx, &sy);
	sx--, sy--;
	scanf("%d %d", &ex, &ey);
	ex--, ey--;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	int tmp = bfs(sx, sy);
	if (tmp == -1)
	{
		printf("-1\n");
		return 0;
	}
	printf("%d\n", -1 + tmp);
	return 0;
}