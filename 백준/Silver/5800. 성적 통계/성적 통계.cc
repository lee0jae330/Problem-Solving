#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int compare(const void* a, const void* b)
{
	int x, y;
	x = *(int*)a;
	y = *(int*)b;
	if (x < y)
		return 1;
	else if (x > y)
		return -1;
	return 0;
}
int main(void)
{
	int N, number;
	scanf("%d", &N);
	int arr[50] = { 0, };
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &number);
		int tmp = number - 1;
		for (int j = 0; j < number; j++)
			scanf("%d", &arr[j]);
		qsort(arr, number, sizeof(arr[0]), compare);
		int max = arr[0];
		int min = arr[tmp];
		int gap=arr[0]-arr[1];
		for (int j = 1; j < number; j++)
		{
			if (arr[j] - arr[j + 1] > gap)
				gap = arr[j] - arr[j + 1];
		}
		printf("Class %d\n", i + 1);
		printf("Max %d, Min %d, Largest gap %d\n", max, min, gap);
	}
	return 0;
}