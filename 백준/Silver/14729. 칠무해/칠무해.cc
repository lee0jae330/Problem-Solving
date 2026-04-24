#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
double arr[10000000] = { 0, };
int compare(const void* a, const void* b)
{
	double x = *(double*)a;
	double y = *(double*)b;
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
		scanf("%lf", &arr[i]);
	qsort(arr, N, sizeof(arr[0]), compare);
	for (int i = 0; i < 7; i++)
		printf("%.3lf\n", arr[i]);
	return 0;
}