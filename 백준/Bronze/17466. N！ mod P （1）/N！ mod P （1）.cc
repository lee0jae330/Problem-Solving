#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int N, K;
	long long result = 1;
	scanf("%d %d", &N, &K);
	if (N >= K)
	{
		printf("0\n");
	}
	else
	{
		for (int i = 1; i <= N; i++)
		{
			result *= (i % K);
			result %= K;
		}
		printf("%d\n", result);
	}
	return 0;
}