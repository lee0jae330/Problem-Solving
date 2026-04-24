#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct a
{
	char id[22];
	char pw[22];
}SITE;

SITE arr[100001];

int compare(const void* a, const void* b)
{
	SITE *x = (SITE*)a;
	SITE* y = (SITE*)b;
	return strcmp(x->id, y->id);
}

int B_search(SITE* a, int len, char* str)
{
	int start = 0;
	int end = len - 1;
	int mid;
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (!strcmp(a[mid].id, str))
			return mid;
		else if (strcmp(a[mid].id, str) < 0)
			start = mid + 1;
		else
			end = mid - 1;
	}
}
int main(void)
{
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%s %s", arr[i].id, arr[i].pw);
	qsort(arr, N, sizeof(arr[0]), compare);
	char tmp[22];
	for (int i = 0; i < M; i++)
	{
		scanf("%s", tmp);
		printf("%s\n", arr[B_search(arr, N, tmp)].pw);
	}
	return 0;
}
