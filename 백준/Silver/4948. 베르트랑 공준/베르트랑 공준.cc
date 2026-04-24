#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#define SIZE 123456
int arr[2 * SIZE + 1] = { 0, };
int main(void)
{
	arr[0] = 1,arr[1] = 1;
	int tmp = 2 * SIZE + 1;
	for (int j = 2; j < tmp / j; j++)
	{
		if (arr[j] == 1)
			continue;
		for (int i = j * j; i < tmp; i += j)
			if (i % j == 0)
				arr[i] = 1;
	}
	int N;
	while (1)
	{
		scanf("%d", &N);
		if (N == 0)
			return 0;
		int count = 0;
		for (int i = N+1; i <= N * 2; i++)
		{
			if (arr[i] == 0)
				count++;
		}
		printf("%d\n", count);
	}
	return 0;
}