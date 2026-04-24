#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int arr[100001];
int arr1[10001];
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
	int N, K;
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	int start = 0, end = start + K-1;
	int sum = 0;
	int index = 0;
	for (int i = start; i < start + K; i++)
		sum += arr[i];
	arr1[index] = sum;
	index++;
	while (1)
	{
		if (start + K >= N)
			break;
		sum -= arr[start];
		sum += arr[start + K];
		arr1[index] = sum;
		index++;
		start++;	
	}
	qsort(arr1, index, sizeof(int), compare);
	printf("%d\n", arr1[0]);
	return 0;
}
