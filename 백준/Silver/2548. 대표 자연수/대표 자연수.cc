#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define SIZE 20001

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
	int tmp = arr[0], cur = 0, min = 0;
	for (int i = 0; i < N; i++)
	{
		min += abs(tmp - arr[i]);
	}
	cur = min;
	for (int i = 1; i < N; i++)
	{
		if (arr[i] == tmp)
			continue;
		for (int j = 0; j < N; j++)
		{
			if (arr[i] > arr[j])
				cur++;
			else
				cur--;
		}
		if (min > cur)
		{
			min = cur;
			tmp = arr[i];
		}
	}
	printf("%d\n", tmp);
	return 0;
}
