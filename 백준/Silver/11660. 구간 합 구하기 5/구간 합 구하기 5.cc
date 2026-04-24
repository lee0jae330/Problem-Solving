#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int arr[1025][1025];
int sum[1025][1025] = { 0, };

int main(void)
{
	int N,M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			scanf("%d", &arr[i][j]);
	}
	for (int i = 0; i < N; i++)
	{
		sum[i][0] = arr[i][0];
		for (int j = 1; j < N; j++)
		{
			sum[i][j] = arr[i][j] + sum[i][j - 1];
		}
	}
	for (int i = 0; i < M; i++)
	{
		int sol = 0;
		int x1, x2, y1, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		for (int j = 0; j <= x2 - x1; j++)
		{
			sol += sum[x1 - 1 + j][y2 - 1] - sum[x1 - 1 + j][y1 - 2];
		}
		printf("%d\n", sol);
	}
	return 0;
}