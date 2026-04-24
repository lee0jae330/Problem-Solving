#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<queue>
#include<memory.h>
#include<string.h>

using namespace std;

char arr[101][101];
int visited[101][101];
int H, W;
int cnt = 0;
int xx[4] = { -1,0,1,0 };
int yy[4] = { 0,1,0,-1 };

void bfs(int x, int y)
{
	visited[x][y] = 1;
	queue<pair<int, int>>q;
	q.push({ x,y });
	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int tx = x + xx[i];
			int ty = y + yy[i];
			if (tx >= 0 && ty >= 0 && tx < H && ty < W)
			{
				if (!visited[tx][ty] && arr[tx][ty] == '#')
				{
					visited[tx][ty] = 1;
					q.push({ tx,ty });
				}
			}
		}
	}
}
int main(void)
{
	int T;
	scanf("%d", &T);
	getchar();
	for (int a = 0; a < T; a++)
	{
		memset(visited, 0, sizeof(visited));
		scanf("%d %d", &H, &W);
		getchar();
		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
				scanf("%c", &arr[i][j]);
			getchar();
		}
		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				if (!visited[i][j] && arr[i][j] == '#')
				{
					bfs(i, j);
					cnt++;
				}
			}
		}
		printf("%d\n",cnt);
		cnt = 0;
	}
	return 0;
}