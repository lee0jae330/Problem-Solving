#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int compare1(const void* a, const void* b) //오름차순
{
	int x = *(int*)a;
	int y = *(int*)b;
	if (x < y)
		return -1;
	else if (x > y)
		return 1;
	return 0;
}
int compare2(const void* a, const void* b) //내림차순
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
	int a[51], b[51];
	int arr2[51];
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &b[i]);
		arr2[i] = b[i];
	}
	qsort(a, N, sizeof(int), compare2);
	qsort(b, N, sizeof(int), compare1);

	int result = 0;
	for (int i = 0; i < N; i++)
	{
		result += a[i] * b[i];
	}
	printf("%d\n", result);
	return 0;
}