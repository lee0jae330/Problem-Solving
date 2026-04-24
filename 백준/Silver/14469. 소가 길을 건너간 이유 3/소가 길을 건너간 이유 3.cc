#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef struct cow
{
	int arrive;
	int time;
}COW;
COW arr[101];
int compare(const void* a, const void* b)
{
	COW* x, * y;
	x = (COW*)a;
	y = (COW*)b;
	if (x->arrive < y->arrive)
		return -1;
	else if (x->arrive > y->arrive)
		return 1;
	return 0;
}
int main(void)
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d %d", &arr[i].arrive, &arr[i].time);
	qsort(arr, N, sizeof(arr[0]), compare);
	int time1 = arr[0].arrive+arr[0].time;
	for (int i = 1; i < N; i++)
	{
		if (time1 < arr[i].arrive)
		{
			time1 = arr[i].arrive + arr[i].time;
		}
		else if(time1>=arr[i].arrive)
		{
			time1 += arr[i].time;
		}
	}
	printf("%d\n", time1);
	return 0;
}