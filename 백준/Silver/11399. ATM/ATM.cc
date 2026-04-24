#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int arr[1001] = { 0, };
int compare(const void* a, const void* b)
{
	int x = *(int*)a;
	int y = *(int*)b;
	if (x < y)
		return -1;
	else if (x > y)
		return 1;
	return 0;
}
int main(void)
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	qsort(arr, N, sizeof(int), compare);
	int time = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = i; j >= 0; j--)
		{
			time += arr[j];
		}
	}
	printf("%d\n", time);
	return 0;
}
