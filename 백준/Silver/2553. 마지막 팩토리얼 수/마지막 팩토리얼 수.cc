#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int N;
	long long int result = 1;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		result *= i;
		result %= 1000000000000;
		while (result % 10 == 0)
		result /= 10;
	}
	result %= 10;
	printf("%lld\n", result);
	return 0;
}