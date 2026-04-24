#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define SIZE 4000001
int arr[SIZE] = { 0, };
int prime[SIZE];
int main(void)
{
	arr[0] = 1, arr[1] = 1;
	for (int i = 2; i < SIZE / i; i++)
	{
		if (arr[i] == 1)
			continue;
		for (int j = i * i; j < SIZE; j += i)
			if (j % i == 0)
				arr[j] = 1;
	}
	int N;
	scanf("%d", &N);
	int index = 0;
	for (int i = 2; i <= N; i++)
	{
		if (arr[i] == 0)
		{
			prime[index] = i;
			index++;
		}
		else
			continue;
	}
	int start = 0, end = 0;
	int sum = 0;
	int count = 0;
	while (1)
	{
		if (sum >= N)
			sum -= prime[start++];
		else if (sum < N)
			sum += prime[end++];
		if (sum == N)
			count++;
		if (end >= index && sum < N)
			break;
	}
	printf("%d\n", count);
	return 0;
}