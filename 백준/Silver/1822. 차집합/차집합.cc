#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define SIZE 500001

int arrA[SIZE];
int arrB[SIZE];
int sol[SIZE];

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

int B_search(int* arr, int len, int target)
{
	int start = 0;
	int end = len - 1;
	int mid;
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (arr[mid] == target)
			return 1;
		else if (arr[mid] < target)
			start = mid + 1;
		else
			end = mid - 1;
	}
	return 0;
}



int main(void)
{
	int N, M;

	scanf("%d %d", &N , &M);
	for (int i = 0; i < N; i++)
		scanf("%d", &arrA[i]);
	for (int i = 0; i < M; i++)
		scanf("%d", &arrB[i]);
	qsort(arrB, M, sizeof(arrB[0]), compare);
	int index = 0;
	for (int i = 0; i < N; i++)
	{
		if (B_search(arrB, M, arrA[i])==0)
		{
			sol[index] = arrA[i];
			index++;
		}
	}
	if (index == 0)
	{
		printf("0\n");
		return 0;
	}
	qsort(sol, index, sizeof(int), compare);
	printf("%d\n", index);
	for (int i = 0; i < index; i++)
		printf("%d ", sol[i]);
	printf("\n");
	return 0;
}