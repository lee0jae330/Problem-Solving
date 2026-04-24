#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int arr[1001][1001];

int main(void)
{
	int N, x, y;
	int input = 1;
	scanf("%d %d %d", &N, &x, &y);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			scanf("%d", &arr[i][j]);
	}
	int num = arr[x - 1][y - 1];
	for (int i = 0; i < N; i++)
	{
		if (i == y - 1)
			continue;
		if (arr[x - 1][i] > num)
		{
			input = 0;
			break;
		}
	}
	if (input)
	{
		for (int i = 0; i < N; i++)
		{
			if (x - 1 == i)
				continue;
			if (arr[i][y - 1] > num)
			{
				input = 0;
				break;
			}
		}
		if (input)
			printf("HAPPY\n");
		else
			printf("ANGRY");
	}
	else
		printf("ANGRY\n");
	return 0;
}