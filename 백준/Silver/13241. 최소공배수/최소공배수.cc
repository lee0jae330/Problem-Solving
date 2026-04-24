#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
long long int gcd(long long int a, long long int b)
{
	long long int small = (a < b) ? a : b;
	long long int big = (a > b) ? a : b;
	while (1)
	{
		if (big % small == 0)
		{
			return small;
		}
		else
		{
			int tmp = small;
			small = big % small;
			big = tmp;
		}
	}
}
int main(void)
{
	long long int a, b;
	scanf("%lld %lld", &a, &b);
	long long int gcdgcd = gcd(a, b);
	long long result = gcdgcd * (a / gcdgcd) * (b / gcdgcd);
	printf("%lld\n", result);
	return 0;
}