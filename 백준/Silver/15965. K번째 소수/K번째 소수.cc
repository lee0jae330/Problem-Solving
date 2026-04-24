#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define SIZE 10000001
int arr[SIZE] = { 0, };
int main(void)
{
	arr[0] = 1, arr[1] = 1;
	for (int i = 2; i < SIZE/i; i++)
	{
		if (arr[i] == 1)
			continue;
		for (int j = i * i; j < SIZE; j += i)
		{
			if (j % i == 0)
				arr[j] = 1;
		}
	}
	int count = 0;
	int num;
	scanf("%d", &num);
	for (int i = 0; i <= SIZE; i++)
	{
		if (arr[i] == 0)
		{
			count++;
			if (count == num)
			{
				printf("%d\n", i);
				break;
			}
		}
	}
}
