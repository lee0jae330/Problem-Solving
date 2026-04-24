#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<algorithm>

using namespace std;

char arr[21][21];
int visited[27] = { 0, };
int cnt = 1;
int x = 0, y = 0;
int finish = 0;
int MAX=1;
void dfs(char v, int x_size, int y_size)
{
	visited[v - 'A'] = 1;
	if (y + 1 < y_size && !visited[arr[x][y + 1] - 'A'])
	{
		cnt++;
		y++;
		MAX = max(MAX, cnt);
		dfs(arr[x][y], x_size, y_size);
		visited[arr[x][y] - 'A'] = 0;
		y--;
		cnt--;
	}
	if (x + 1 < x_size && !visited[arr[x + 1][y] - 'A'])
	{
		cnt++;
		x++;
		MAX = max(MAX, cnt);
		dfs(arr[x][y], x_size, y_size);
		visited[arr[x][y] - 'A'] = 0;
		x--;
		cnt--;
	}
	if (y - 1 >= 0 && !visited[arr[x][y - 1] - 'A'])
	{
		cnt++;
		y--;
		MAX = max(MAX, cnt);
		dfs(arr[x][y], x_size, y_size);
		visited[arr[x][y] - 'A'] = 0;
		y++;
		cnt--;
	}
	if (x - 1 >= 0 && !visited[arr[x - 1][y] - 'A'])
	{
		cnt++;
		x--;
		MAX = max(MAX, cnt);
		dfs(arr[x][y], x_size, y_size);
		visited[arr[x][y] - 'A'] = 0;
		x++;
		cnt--;
	}
}
int main(void)
{
	int R, C;
	scanf("%d", &R);
	getchar();
	scanf("%d", &C);
	getchar();
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			scanf("%c", &arr[i][j]);
		}
		getchar();
	}
	
	dfs(arr[0][0],R,C);
	printf("%d\n", MAX);
	return 0;
}