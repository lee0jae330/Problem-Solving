#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int compare(const void* a, const void* b)
{
	int x = *(int*)a;
	int y = *(int*)b;
	if (x < y)
		return 1;
	else if (x > y)
		return -1;
	return 0;
}
int main(void)
{
	int N, score, P;
	int arr[50] = { 0, };
	int arr1[100] = { 0, };
	scanf("%d %d %d", &N, &score, &P);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	if (N < P)
	{
		int input = 0;
		int tmp;
		for (int j = 0; j < N; j++)
		{
			if (score == arr[j])
			{
				input = 1;
				tmp = j + 1;
				break;
			}
		}
		if (input == 1)
		{
			printf("%d\n", tmp);
		}
		else
		{
			arr[N] = score;
			qsort(arr, N + 1, sizeof(arr[0]), compare);
			for (int j = 0; j <= N; j++)
			{
				if (arr[j] == score)
				{
					int tmp = j + 1;
					printf("%d\n", tmp);
					break;
				}
			}
		}
	}
	else
	{
		int input = 0;
		int tmp;
		for (int j = 0; j < N; j++)
		{
			if (score == arr[j])
				input++;
		}
		if (score == arr[N - 1])
		{
			printf("-1\n");
			return 0;
		}
		if (input != 0)
		{
			if (input == N)
				printf("-1\n");
			else
			{
				for (int j = 0; j < N; j++)
				{
					if (score == arr[j])
					{
						tmp = j + 1;
						break;
					}
				}
				
				if (tmp >= N)
					printf("-1\n");
				else
					printf("%d\n", tmp);
			}
		}
		else
		{
			for (int i = 0; i < N; i++)
				arr1[i] = arr[i];
			arr1[N] = score;
			int tmp=0;
			qsort(arr1, N + 1, sizeof(arr1[0]), compare);
			for (int i = 0; i <= N; i++)
			{
				if (score == arr1[i])
				{
					tmp = i;
					break;
				}
			}
			if (tmp < N)
			{
				printf("%d\n", tmp+1);
			}
			else
				printf("-1\n");
		}
	}
	return 0;
}