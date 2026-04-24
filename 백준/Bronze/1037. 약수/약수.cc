#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

long long arr[51];

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
		scanf("%lld", &arr[i]);
	qsort(arr, N, sizeof(arr[0]), compare);
	if (N == 1)
		printf("%lld\n", arr[0] * arr[0]);
	else
	{
		printf("%lld\n", arr[0] * arr[N - 1]);
	}
	return 0;
}