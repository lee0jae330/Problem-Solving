#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define SIZE 1000001
int arr[SIZE];
int arr1[SIZE];
int sol[SIZE] = { 0, };
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
int Bsearch(int* x, int len, int target)
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
int main(void)
{
	int N, M,T;
	scanf("%d", &T);
	for(int j=0;j<T;j++)
	{
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
			scanf("%d", &arr[i]);
		scanf("%d", &M);
		for (int i = 0; i < M; i++)
			scanf("%d", &arr1[i]);
		qsort(arr, N, sizeof(int), compare);
		for (int i = 0; i < M; i++)
		{
			printf("%d\n", Bsearch(arr, N, arr1[i]));
		}
	}
	return 0;
}