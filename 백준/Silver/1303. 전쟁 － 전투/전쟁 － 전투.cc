#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<queue>
#include<algorithm>
#include<memory.h>
#include<string.h>
#include<math.h>
using namespace std;

int N, M;
char arr[101][101];
int visited[101][101];
int xx[4] = { -1,0,1,0 };
int yy[4] = { 0,1,0,-1 };
long long int sum_w = 0;
long long int sum_b = 0;

void bfs_w(int x, int y)
{
	queue<pair<int,int>>q;
	visited[x][y]=1;
	q.push({ x,y });
	int num = 0;
	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		num++;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int tx = x + xx[i];
			int ty = y + yy[i];
			if (tx >= 0 && ty >= 0 && tx < M && ty < N)
			{
				if (!visited[tx][ty] && arr[tx][ty] == 'W')
				{
					visited[tx][ty] = 1;
					q.push({ tx,ty });
				}
			}
		}
	}
	sum_w += pow(num, 2);
}

void bfs_b(int x, int y)
{
	queue<pair<int, int>>q;
	visited[x][y] = 1;
	q.push({ x,y });
	int num = 0;
	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		num++;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int tx = x + xx[i];
			int ty = y + yy[i];
			if (tx >= 0 && ty >= 0 && tx < M && ty < N)
			{
				if (!visited[tx][ty] && arr[tx][ty] == 'B')
				{
					visited[tx][ty] = 1;
					q.push({ tx,ty });
				}
			}
		}
	}
	sum_b += pow(num, 2);
}
int main(void)
{
	scanf("%d %d", &N, &M);
	getchar();
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
			scanf("%c", &arr[i][j]);
		getchar();
	}
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!visited[i][j] && arr[i][j] == 'W')
				bfs_w(i,j);
			if (!visited[i][j] && arr[i][j] == 'B')
				bfs_b(i, j);
		}
	}
	printf("%lld %lld\n", sum_w, sum_b);
	return 0;
}