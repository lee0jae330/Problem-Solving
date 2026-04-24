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
	long long total = 0;
	qsort(arr, N, sizeof(int), compare);
	for (int i = 0; i < N; i++)
	{
		int tmp = arr[i] - i;
		if (tmp >= 0)
			total += tmp;
	}
	printf("%lld\n", total);
	return 0;
}