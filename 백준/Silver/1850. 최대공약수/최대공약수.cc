#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
unsigned long long gcd(unsigned long long x, unsigned long long y)
{
	unsigned long long small = (x < y) ? x : y;
	unsigned long long big = (x > y) ? x : y;
	while (1)
	{
		if (big % small == 0)
		{
			return small;
			break;
		}
		else
		{
			unsigned long long tmp = small;
			small = big % small;
			big = tmp;
		}
	}
}
int main(void)
{
	unsigned long long a, b;
	scanf("%llu %llu", &a, &b);
	for (unsigned long long i = 0; i < gcd(a,b); i++)
		printf("1");
	printf("\n");
	return 0;
}