#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	long long N, M;
	scanf("%lld %lld", &N, &M);
	long long a;
	a = N - M;
	a = (a > 0) ? a : -a;
	printf("%lld", a);
	return 0;
}