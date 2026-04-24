#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef struct student
{
	int number;
	int score=0;
}STU;
int problem[102] = { 0, };
STU arr[102];
int compare(const void* a, const void* b)
{
	STU* x, * y;
	x = (STU*)a;
	y = (STU*)b;
	if (x->score == y->score)
	{
		if (x->number < y->number)
			return -1;
		else
			return 1;
	}
	else if (x->score < y->score)
		return 1;
	else
		return -1;
}
int main(void)
{
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &problem[i]);
		getchar();
	}
	for (int i = 0; i < M; i++)
	{
		scanf("%d", &arr[i].number);
		getchar();
		for (int j = 0; j < N; j++)
		{
			char tmp;
			scanf("%c", &tmp);
			getchar();
			if (tmp == 'O')
				arr[i].score += problem[j];
			else
				continue;
		}
	}
	qsort(arr, M, sizeof(arr[0]), compare);
	printf("%d %d\n", arr[0].number, arr[0].score);
	return 0;
}