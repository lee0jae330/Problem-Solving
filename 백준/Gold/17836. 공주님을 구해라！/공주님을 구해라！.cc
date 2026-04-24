#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;

int arr[101][101];
int visited[101][101][2];
int xx[4] = { -1,0,1,0 };
int yy[4] = { 0,1,0,-1 };
int N, M, T;

queue<pair<pair<int, int>, int>>q;

void bfs(int x, int y)
{
	visited[x][y][0] = 0;
	q.push({ {x,y},0 });
	while (!q.empty())
	{
		x = q.front().first.first;
		y = q.front().first.second;
		int gram = q.front().second;
		q.pop();
		if (x == N - 1 && y == M - 1)
			return;
		if (!gram)
		{
			for (int i = 0; i < 4; i++)
			{
				int tx = x + xx[i];
				int ty = y + yy[i];
				if (tx >= 0 && ty >= 0 && tx < N && ty < M)
				{
					if (!visited[tx][ty][gram] && arr[tx][ty] != 1)
					{
						if (arr[tx][ty] == 0)
						{
							visited[tx][ty][gram] = visited[x][y][gram] + 1;
							q.push({ {tx,ty},0 });
						}
						else
						{
							visited[tx][ty][gram+1] = visited[x][y][gram] + 1;
							q.push({ {tx,ty},1 });
						}
					}
				}
			}
		}
		else
		{
			if (x + 1< N&&!visited[x+1][y][gram] )
			{
				visited[x + 1][y][gram] = visited[x][y][gram] + 1;
				q.push({ {x + 1,y},1 });
			}
			if (y + 1 < M&&!visited[x][y+1][gram])
			{
				visited[x][y + 1][gram] = visited[x][y][gram] + 1;
				q.push({ {x,y + 1},1 });
			}
		}
	}
}

int main(void)
{
	scanf("%d %d %d", &N, &M, &T);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	bfs(0, 0);
	if (!visited[N - 1][M - 1][0]&&!visited[N-1][M-1][1])
		printf("Fail\n");
	else
	{
		int m;
		if (visited[N - 1][M - 1][0] && visited[N - 1][M - 1][1])
			m = min(visited[N - 1][M - 1][0], visited[N - 1][M - 1][1]);
		else if (visited[N - 1][M - 1][0])
			m = visited[N - 1][M - 1][0];
		else
			m = visited[N - 1][M - 1][1];
		if (m <= T)
			printf("%d\n", m);
		else
			printf("Fail\n");
	}
	return 0;
}