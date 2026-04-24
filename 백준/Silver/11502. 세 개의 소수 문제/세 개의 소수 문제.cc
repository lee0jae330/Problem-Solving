#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define SIZE 1001
int arr[SIZE] = { 0, };
int prime[SIZE] = { 0, };
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
	arr[0] = 1, arr[1] = 1;
	for (int i = 2; i < SIZE / i; i++)
	{
		if (arr[i] == 1)
			continue;
		for (int j = i * i; j < SIZE; j += i)
		{
			if (j % i == 0)
				arr[j] = 1;
		}
	}
	int index = 0;
	for (int i = 0; i < SIZE;i++)
	{
		if (arr[i] == 0)
		{
			prime[index] = i;
			index++;
		}
	}
	int T, K;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		int tmp[3];
		scanf("%d", &K);
		tmp[0] = 3;

		K -= tmp[0];
		for (int j = 0; j < index; j++)
		{
			tmp[1] = prime[j];
			tmp[2] = K -tmp[1];
			if (arr[tmp[2]] == 0)
			{
				qsort(tmp, 3, sizeof(int), compare);
				printf("%d %d %d\n", tmp[0], tmp[1], tmp[2]);
				break;
			}
		}
	}
	return 0;
}