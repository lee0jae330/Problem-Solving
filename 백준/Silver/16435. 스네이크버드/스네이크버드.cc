#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int arr[10001] = { 0, };
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
	int N, L;
	scanf("%d %d", &N, &L);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	qsort(arr, N, sizeof(int), compare);
	for (int i = 0; i < N; i++)
	{
		if (arr[i] <= L)
			L++;
		else
			break;
	}
	printf("%d\n", L);
	return 0;
}