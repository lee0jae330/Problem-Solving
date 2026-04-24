#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<queue>
#include<memory.h>
#include<string.h>

using namespace std;

char arr[52][52];
int r, c;
int visited[52][52];
int dist[52][52];
int time[52][52];
int xx[4] = { -1 ,0,1,0 };
int yy[4] = { 0,1,0,-1 };
queue<pair<int, int>>q1;
queue<pair<int, int>>q2;

void water()
{
	while (!q2.empty())
	{
		int x = q2.front().first;
		int y = q2.front().second;
		visited[x][y] = 1;
		q2.pop();
		int t = time[x][y];
		for (int i = 0; i < 4; i++)
		{
			int tx = x + xx[i];
			int ty = y + yy[i];
			if (tx >= 0 && ty >= 0 && tx < r && ty < c)
			{
				if (!visited[tx][ty] && arr[tx][ty] == '.')
				{
					visited[tx][ty] = 1;
					time[tx][ty] += t+1;
					q2.push({ tx,ty });
				}
			}
		}
	}
}

void bfs(int x, int y)
{
	memset(visited, 0, sizeof(visited));
	visited[x][y] = 1;
	q1.push({ x,y });
	while (!q1.empty())
	{
		x = q1.front().first;
		y = q1.front().second;
		int t = dist[x][y];
		q1.pop();
		for (int i = 0; i < 4; i++)
		{
			int tx = x + xx[i];
			int ty = y + yy[i];
			if (tx >= 0 && ty >= 0 && tx < r && ty < c)
			{
				if (!visited[tx][ty] && (arr[tx][ty] == '.'||arr[tx][ty]=='D'))
				{
					if (time[tx][ty])
					{
						if (t + 1 >= time[tx][ty])
							continue;
					}
					visited[tx][ty] = 1;
					dist[tx][ty] += t + 1;
					q1.push({ tx,ty });
				}
			}
		}
	}
}

int main(void)
{
	int x, y;
	int sol_x, sol_y;
	scanf("%d %d", &r, &c);
	getchar();
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			scanf("%c", &arr[i][j]);
			if (arr[i][j] == 'S')
			{
				x = i, y = j;
			}
			else if (arr[i][j] == '*')
				q2.push({ i,j });
			else if (arr[i][j] == 'D')
				sol_x = i, sol_y = j;
		}
		getchar();
	}
	water();
	bfs(x, y);
	
	if (!dist[sol_x][sol_y])
		printf("KAKTUS\n");
	else
		printf("%d\n", dist[sol_x][sol_y]);
	return 0;
}