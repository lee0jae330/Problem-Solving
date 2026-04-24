#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<queue>
#include<algorithm>
#include<memory.h>
#include<string.h>

using namespace std;
int N, M;
char arr[3001][3001];
int visited[3001][3001];
int xx[4] = { -1,0,1,0 };
int yy[4] = { 0,1,0,-1 };
int sx, sy;
queue<pair<int, int>>q;
vector<int>v;

void bfs(int x,int y)
{
	memset(visited, -1, sizeof(visited));
	visited[x][y] = 0;
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
			if (tx >= 0 && ty >= 0 && tx < N && ty < M)
			{
				if (visited[tx][ty] == -1 && arr[tx][ty] != '1')
				{
					visited[tx][ty] = visited[x][y] + 1;
					q.push({ tx,ty });
					if (arr[tx][ty] == '3' || arr[tx][ty] == '4' || arr[tx][ty] == '5')
					{
						v.push_back(visited[tx][ty]);
					}
				}
			}
		}
	}
}

int main(void)
{
	scanf("%d %d", &N, &M);
	getchar();
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%c", &arr[i][j]);
			if (arr[i][j] == '2')
				sx = i, sy = j;
		}
		getchar();
	}
	bfs(sx, sy);
	if (v.size() == 0)
	{
		printf("NIE\n");
		return 0;
	}
	sort(v.begin(), v.end());
	printf("TAK\n");
	printf("%d\n", v[0]);
	return 0;
}