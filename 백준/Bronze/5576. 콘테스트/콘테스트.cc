#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
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
	int arr[20] = { 0, };
	for (int i = 0; i < 20; i++)
		scanf("%d", &arr[i]);
	int W[10] = { 0, };
	int K[10] = { 0, };
	for (int i = 0; i < 10; i++)
		W[i] = arr[i];
	for (int i = 10; i < 20; i++)
		K[i - 10] = arr[i];
	qsort(W, 10, sizeof(W[0]), compare);
	qsort(K, 10, sizeof(K[0]), compare);
	printf("%d %d\n", W[7] + W[8] + W[9], K[7] + K[8] + K[9]);
	return 0;
}