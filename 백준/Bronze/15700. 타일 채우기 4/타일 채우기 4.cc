#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	unsigned long long N, M;
	scanf("%lld %lld", &N, &M);
	unsigned long long a;
	a = (N * M) / 2;
	printf("%lld\n", a);
	return 0;
}