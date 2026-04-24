#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef struct keyboard
{
	int number;
	int time;
	char word;
}KB;
KB arr[1001];
int compare(const void* a, const void* b)
{
	KB* x, * y;
	x = (KB*)a;
	y = (KB*)b;
	if (x->time == y->time)
	{
		if (x->number < y->number)
			return -1;
		else if (x->number > y->number)
			return 1;
	}
	else if (x->time < y->time)
		return -1;
	else
		return 1;
}
int main(void)
{
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++)
		scanf("%d %d %c", &arr[i].number, &arr[i].time, &arr[i].word);
	qsort(arr, M, sizeof(arr[0]), compare);
	for (int i = 0; i < M; i++)
		printf("%c", arr[i].word);
	return 0;
}