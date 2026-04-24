#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	long long int A, B;
	scanf("%lld %lld", &A, &B);
	if (A <= B)
	{
		printf("%lld\n", (A + B) * (B - A + 1) / 2);
	}
	else
		printf("%lld\n", (A + B) * ( A-B + 1) / 2);
	return 0;
}