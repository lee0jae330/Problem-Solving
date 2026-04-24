#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int arr[15001] = { 0, };
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
	int N, K;
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	qsort(arr, N, sizeof(int), compare);
	int count = 0, start = 0, end = N-1, sum = 0;
	while (arr[start] <= arr[end] && start != end)
	{
		if (arr[start] + arr[end] == K)
		{
			count++;
			start++;
			end--;
		}
		else if (arr[start] + arr[end] < K)
			start++;
		else
			end--;
	}
	printf("%d\n", count);
	return 0;
}