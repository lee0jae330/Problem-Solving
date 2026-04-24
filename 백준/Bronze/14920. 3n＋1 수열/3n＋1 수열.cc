#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
	unsigned long long int N;
	long long int num = 1;
	scanf("%llu", &N);
	while (1)
	{
		if (N == 1)
		{
			printf("%lld\n", num);
			return 0;
		}
		if (N % 2 == 1)
		{
			N = 3 * N + 1;
		}
		else
		{
			N /= 2;
		}
		num++;
	}
	return 0;
}