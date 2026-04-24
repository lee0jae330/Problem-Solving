#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef struct school
{
	char name[22];
	int tnf;
}School;
int compare(const void* a, const void* b)
{
	School* x, * y;
	x = (School*)a;
	y = (School*)b;
	if (x->tnf < y->tnf)
		return -1;
	else if (x->tnf > y->tnf)
		return 1;
	return 0;
}
int main(void)
{
	int T;
	School arr[100];
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		int N;
		scanf("%d", &N);
		for (int j = 0; j < N; j++)
			scanf("%s %d", arr[j].name, &arr[j].tnf);
		qsort(arr, N, sizeof(arr[0]), compare);
		printf("%s\n", arr[N - 1].name);
	}
	return 0;
}