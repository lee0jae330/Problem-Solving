#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
unsigned long long powpow(unsigned long long a, unsigned long long b, unsigned long long c)
{
	if (b == 0)
		return 1;
	unsigned long long n = powpow(a, b / 2, c);
	unsigned long long tmp = n * n %c;
	if (b % 2 == 0)
		return tmp;
	else
		return a * tmp % c;
}
int main(void)
{
	unsigned long long p, a;
	while (1)
	{
		int input = 0;
		scanf("%llu %llu", &p, &a);
		if (p == 0 && a == 0)
			return 0;
		for (int i = 2; i <= sqrt(p); i++)
		{
			if (p % i == 0)
			{
				input = 1;
				break;
			}
		}
		if (input == 1)
		{
			if (powpow(a, p, p) == a)
				printf("yes\n");
			else
				printf("no\n");
		}
		else
			printf("no\n");
	}
	return 0;
}