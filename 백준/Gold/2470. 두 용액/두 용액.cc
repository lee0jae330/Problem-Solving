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
	int start = 0, end = N - 1;
	int tmp = 2147483647;
	int n1, n2;
	while (start<end)
	{
		if (abs(arr[start] + arr[end]) < tmp)
		{
			
			tmp = abs(arr[start] + arr[end]);
			n1 = arr[start];
			n2 = arr[end];
		}
		if (arr[start] + arr[end] < 0)
		{
			start++;
		}
		else
			end--;
		
	}
	printf("%d %d\n", n1, n2);
}