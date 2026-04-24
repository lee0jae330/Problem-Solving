#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<queue>
#include<memory.h>
#include<string.h>
#include<vector>

using namespace std;

int N, M;
char arr[1001][1001];
int carr[1001][1001];
int visited[1001][1001];
int wall[1001][1001];
int xx[4] = { -1,0,1,0 };
int yy[4] = { 0,1,0,-1 };

queue<pair<int, int>>q;
vector<pair<int, int>>w;

void bfs(int x, int y)
{
	w.clear();
	visited[x][y] = 1;
	q.push({ x,y });
	int cnt = 1;
	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
	
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int tx = x + xx[i];
			int ty = y + yy[i];
			if (tx >= 0 && ty >= 0 && tx < N && ty < M)
			{
				if (!visited[tx][ty] && arr[tx][ty] == '0')
				{
					visited[tx][ty] = 1;
					q.push({ tx,ty });
					cnt++;
				}
				if (!wall[tx][ty] && arr[tx][ty] == '1')
				{
					wall[tx][ty] = 1;
					w.push_back({ tx,ty });
				}
			}
		}
	}
	for (int i = 0; i < w.size(); i++)
	{
		carr[w[i].first][w[i].second]+=cnt;
		wall[w[i].first][w[i].second] = 0;
	}
}

int main(void)
{
	scanf("%d %d", &N, &M);
	getchar();
	for (int i = 0; i < N; i++)
	{
		scanf("%s", &arr[i]);
		for (int j = 0; j < M; j++)
		{
			carr[i][j] = arr[i][j] - '0';
		}
		getchar();
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == '0'&&!visited[i][j])
			{
				bfs(i, j);
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			printf("%c", '0' + (carr[i][j] % 10));
		printf("\n");
	}
	return 0;
}