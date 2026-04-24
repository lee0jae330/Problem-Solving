#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

int main(void)
{
	unsigned long long N;
	scanf("%llu", &N);
	unsigned long long a = sqrt(N);
	if (pow(a, 2) < N)
	{
		printf("%llu\n", a + 1);
	}
	else
		printf("%llu\n", a);
	return 0;
}