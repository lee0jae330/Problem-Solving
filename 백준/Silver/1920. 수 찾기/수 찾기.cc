#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define SIZE 100001
long long arr[SIZE];
long long arr1[SIZE];
int arr2[SIZE];
int bsearch(long long* x, int len, long long target)
{
	int first = 0;
	int last = len - 1;
	int mid;
	while (first <= last)
	{
		mid = (first + last) / 2;
		if (target == x[mid])
			return 1;
		else if (target > x[mid])
			first = mid + 1;
		else
			last = mid - 1;
	}
	return 0;
}
int compare(const void* a, const void* b)
{
	long long x = *(long long*)a;
	long long y = *(long long*)b;
	if (x < y)
		return -1;
	else if (x > y)
		return 1;
	return 0;
}
int main(void)
{
	int N, M;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%lld", &arr[i]);
	qsort(arr, N, sizeof(long long), compare);
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		scanf("%lld", &arr1[i]);
		arr2[i] = bsearch(arr,N, arr1[i]);
	}
	for (int i = 0; i < M; i++)
		printf("%d\n", arr2[i]);
	return 0;
}