#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define SIZE 1000001
int arr[SIZE] = { 0, };
int main(void)
{
	arr[0] = 1, arr[1] = 1;
	for (int j = 2; j < SIZE / j; j++)
	{
		if (arr[j] == 1)
			continue;
		for (int i = j * j; i < SIZE; i += j)
			if (i % j == 0)
				arr[i] = 1;
	}
	int M, N;
	scanf("%d %d", &M, &N);
	int count = 0;
	for (int i = M; i <= N; i++)
	{
		if (arr[i] == 0)
			printf("%d\n", i);
	}
	return 0;
}