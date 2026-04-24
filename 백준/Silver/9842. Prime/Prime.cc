#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define SIZE 1000001
int arr[SIZE] = { 0, };
int main(void)
{
	arr[0] = 1, arr[1] = 1;
	for (int j = 2; j < SIZE / j; j++)
	{
		if (arr[j] == 1)
			continue;
		for (int i = j * j; i < SIZE; i += j)
			if (i % j == 0)
				arr[i] = 1;
	}
	int count=0;
	int n;
	scanf("%d", &n);
	for (int i = 0; i <= SIZE; i++)
	{
		if (arr[i] == 0)
		{
			count++;
			if (count == n)
			{
				printf("%d\n", i);
				break;
			}

		}
	}
	return 0;
}