#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<queue>
#include<algorithm>
#include<string.h>
#include<memory.h>

using namespace std;

char arr[51][51];
int dist[51][51];
int visited[51][51];
int N, M;
int xx[4] = { -1,0,1,0 };
int yy[4] = { 0,1,0,-1 };
queue<pair<int, int>>q;

int bfs(int x, int y)
{
	memset(dist, 0, sizeof(dist));
	memset(visited, 0, sizeof(visited));
	visited[x][y] = 1;
	dist[x][y] = 0;
	int d = -1;
	q.push({ x,y });
	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();
		d = max(dist[x][y], d);
		for (int i = 0; i < 4; i++)
		{
			int tx = x + xx[i];
			int ty = y + yy[i];
			if (tx >= 0 && ty >= 0 && tx < N && ty < M)
			{
				if (!visited[tx][ty]&& arr[tx][ty] == 'L')
				{
					visited[tx][ty] = 1;
					dist[tx][ty] = dist[x][y] + 1;
					q.push({ tx,ty });
				}
			}
		}
	}
	return d;
}

int main(void)
{
	scanf("%d %d", &N, &M);
	getchar();
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			scanf("%c", &arr[i][j]);
		getchar();
	}
	int result = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == 'L')
			{
				result = max(result, bfs(i, j));
			}
		}
	}
	printf("%d\n", result);
	return 0;
}