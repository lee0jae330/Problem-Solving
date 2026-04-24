#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define SIZE 100001
int arr[SIZE];
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
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	qsort(arr, N, sizeof(int),compare);
	int max = arr[0];
	for (int i = 1; i < N; i++)
	{
		if (max <= arr[i] * (i + 1))
		{
			max = arr[i] * (i + 1);
		}
	}
	printf("%d\n", max);
	return 0;
}