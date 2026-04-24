#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int compare(const void* a, const void* b)
{
	double x = *(double*)a;
	double y = *(double*)b;
	if (x < y)
		return 1;
	else if (x > y)
		return -1;
	return 0;
}
int main(void)
{
	int N;
	double arr[1000] = { 0, };
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%lf", &arr[i]);
	qsort(arr, N, sizeof(arr[0]), compare);
	double max = arr[0];
	for (int i = 0; i < N; i++)
		arr[i] = arr[i] / max * 100.;
	double avg=0;
	for (int i = 0; i < N; i++)
		avg += arr[i];
	avg /= N;
	printf("%lf\n", avg);
	return 0;
}