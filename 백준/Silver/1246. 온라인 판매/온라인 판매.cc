#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int p[1001];
int price[1001] = { 0, };
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
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++)
		scanf("%d", &p[i]);
	qsort(p, M, sizeof(int), compare);
	for (int i = 0; i < M; i++)
	{
		if (N >=M)
		{
			int tmp = (M - i) * p[i];
			price[i] = tmp;
		}
		else
		{
			if (i < M - 1)
			{
				if (N >= (M - i))
				{
					int tmp = (M - i) * p[i];
					price[i] = tmp;
				}
				else
				{
					int tmp = N * p[i];
					price[i] = tmp;
				}
			}
			else if(i==M-1)
			{
				price[i] = p[i];
			}
		}
	}

	int max = price[0];
	for (int i = 1; i < M; i++)
	{
		if (max < price[i])
			max = price[i];
	}
	int index;
	for (int i = 0; i < M; i++)
	{
		if (price[i] == max)
			index = i;
	}
	printf("%d %d\n", p[index], max);
	return 0;
}