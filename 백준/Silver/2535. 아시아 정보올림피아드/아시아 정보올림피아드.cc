#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef struct user
{
	int country;
	int number;
	int score;

}USER;
int compare(const void* a, const void* b)
{
	USER* x, * y;
	x = (USER*)a;
	y = (USER*)b;
	if (x->score < y->score)
		return 1;
	else if (x->score > y->score)
		return -1;
	return 0;
}
int main(void)
{
	int N;
	USER arr[200];
	scanf("%d", &N);
	for (int i = 0; i < N;i++)
		scanf("%d %d %d", &arr[i].country, &arr[i].number, &arr[i].score);
	qsort(arr, N, sizeof(arr[0]), compare);
	int n1 = arr[0].country;//금
	int n2 = arr[1].country;//은
	for (int i = 0; i < 2; i++)
		printf("%d %d\n", arr[i].country, arr[i].number);
	if (n1 == n2)
	{
		for (int i = 2; i < N; i++)
		{
			if (arr[i].country != n1)
			{
				printf("%d %d\n", arr[i].country, arr[i].number);
				break;
			}
		}
	}
	else
		printf("%d %d\n", arr[2].country, arr[2].number);
	return 0;
}