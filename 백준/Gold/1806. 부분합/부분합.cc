#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int arr[100001];
int main(void)
{
	int N, K;
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	int min = N;
	int start = 0, end = 0;
	int sum = 0;
	int tmp = -10;
	while (1)
	{
		if (sum >= K)
		{
			tmp = end - start;
			if (tmp < min)
				min = tmp;
			sum -= arr[start++];
		}
		else if (sum < K)
			sum += arr[end++];
		if (end >= N && sum<K)
		{
			if (tmp == -10)
			{
				printf("0\n");
				return 0;
			}

			break;
		}
	}
	printf("%d\n", min);
	return 0;
}