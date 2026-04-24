#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<queue>
#include<algorithm>

using namespace std;

int arr[1001][1001];
int c_arr[1001][1001];
int dist[1001][1001];
queue<pair<int,int>>q;
int visited[1001][1001];
int N, M;
void bfs(int x,int y)
{
	visited[x][y] = 1;
	dist[x][y] = 0;
	q.push({ x,y });
	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();
		if (x - 1 >= 0 && arr[x - 1][y] && !visited[x - 1][y])
		{
			visited[x - 1][y] = 1;
			dist[x - 1][y] = dist[x][y] + 1;
			q.push({ x - 1,y });
		}
		if (x + 1 < N && arr[x + 1][y] && !visited[x + 1][y])
		{
			visited[x + 1][y] = 1;
			dist[x + 1][y] = dist[x][y] + 1;
			q.push({ x + 1,y });
		}
		if (y - 1 >= 0 && arr[x][y - 1] && !visited[x][y - 1])
		{
			visited[x][y - 1] = 1;
			dist[x][y - 1] = dist[x][y] + 1;
			q.push({ x,y - 1 });
		}
		if (y + 1 < M && arr[x][y + 1] && !visited[x][y + 1])
		{
			visited[x][y + 1] = 1;
			dist[x][y + 1] = dist[x][y]+1;
			q.push({ x,y + 1 });
		}
	}
}

int main(void)
{
	
	int x,y;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 2)
				x = i, y = j;
			if (arr[i][j] == 2 || arr[i][j] == 0)
				c_arr[i][j] = 1;
		}
	}
	bfs(x, y);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (!dist[i][j])
			{
				if (c_arr[i][j])
					printf("0 ");
				else
					printf("-1 ");
			}
			else
			{
				printf("%d ", dist[i][j]);
			}
			
		}
		printf("\n");
	}
	return 0;
}