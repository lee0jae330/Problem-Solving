#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	unsigned long long A, B;
	scanf("%lld %lld", &A, &B);
	printf("%lld\n", (A + B) * (A - B));
	return 0;
}