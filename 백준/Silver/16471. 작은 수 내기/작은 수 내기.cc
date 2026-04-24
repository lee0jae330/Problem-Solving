#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int arr[100001] = { 0, };
int arr1[100001] = { 0, };
int compare1(const void* a, const void* b)
{
	int x = *(int*)a;
	int y = *(int*)b;
	if (x < y)
		return -1;
	else if (x > y)
		return 1;
	return 0;
} //오름차순
int compare2(const void* a, const void* b)
{
	int x = *(int*)a;
	int y = *(int*)b;
	if (x < y)
		return 1;
	else if (x > y)
		return -1;
	return 0;
}//내림차순
int main(void)
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr1[i]);
	qsort(arr, N, sizeof(int), compare1);
	qsort(arr1, N, sizeof(int), compare2);
	int point = 0;
	int index = N / 2;
	for (int i = 0; i <= N / 2; i++)
	{
		if (arr[i] < arr1[index])
			point++;
		else if (arr[i] == arr1[index])
			continue;
		else
			break;
		index--;
	}
	if (point >= (N + 1) / 2)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}