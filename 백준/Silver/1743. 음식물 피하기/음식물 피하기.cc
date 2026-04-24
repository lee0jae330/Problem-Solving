#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<queue>
#include<algorithm>
#include<vector>

using namespace std;

int arr[102][102];
int visited[102][102];
int N, M, K;
vector<int>v;
int xx[4] = { -1,0,1,0 };
int yy[4] = { 0,1,0,-1 };

queue<pair<int, int>>q;

void bfs(int x, int y)
{
	visited[x][y] = 1;
	q.push({ x,y });
	int size = 0;
	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		size++;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int tx = x + xx[i];
			int ty = y + yy[i];
			if (tx >= 1 && ty >= 1 && tx <= N && ty <= M)
			{
				if (!visited[tx][ty] && arr[tx][ty])
				{
					visited[tx][ty] = 1;
					q.push({ tx,ty });
				}
			}
		}
	}
	v.push_back(size);
}

int main(void)
{
	int a, b;
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i < K; i++)
	{
		scanf("%d %d", &a, &b);
		arr[a][b] = 1;
	}
	
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (!visited[i][j] && arr[i][j])
			{
				bfs(i, j);
			}
		}
	}
	sort(v.begin(), v.end());
	printf("%d\n", v[v.size() - 1]);
	return 0;
}