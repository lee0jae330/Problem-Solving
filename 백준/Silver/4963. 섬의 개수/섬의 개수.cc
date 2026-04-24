#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<memory.h>
#include<string.h>

using namespace std;

int arr[51][51];
int visited[51][51];
int xx[8] = { -1,-1,0,1,1,1,0,-1 };
int yy[8] = { 0,1,1,1,0,-1,-1,-1 };
int N, K;

void dfs(int x,int y)
{
	visited[x][y] = 1;
	for (int i = 0; i < 8; i++)
	{
		int tmp_x = xx[i] + x;
		int tmp_y = yy[i] + y;
		if (tmp_x >= 0 && tmp_y >= 0 && tmp_x < N && tmp_y < K)
		{
			if (!visited[tmp_x][tmp_y] && arr[tmp_x][tmp_y])
			{
				visited[tmp_x][tmp_y];
				dfs(tmp_x, tmp_y);
			}
		}
	}
}

int main(void)
{
	int count = 0;
	while (1)
	{
		count = 0;
		memset(visited, 0, sizeof(visited));
		memset(arr, 0, sizeof(arr));
		scanf("%d %d", &K, &N);
		if (N == 0 && K == 0)
			break;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < K; j++)
				scanf("%d", &arr[i][j]);
			getchar();
		}		
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < K;j++)
			{
				if (!visited[i][j] && arr[i][j])
				{
					dfs(i, j);
					count++;
				}
			}
		}
		printf("%d\n", count);
	}
	return 0;
}