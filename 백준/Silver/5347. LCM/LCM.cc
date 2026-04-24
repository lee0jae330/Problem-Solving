#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	long long gcd,lcm, N, a, b;
	scanf("%lld", &N);
	for (long long i = 0; i < N; i++)
	{
		scanf("%lld %lld", &a, &b);
		long long max = (a > b) ? a : b;
		long long min = (a < b) ? a : b;
		while (1)
		{
			if (max % min == 0)
			{
				gcd = min;
				break;
			}
			else
			{
				long long tmp = min;
				min = max % min;
				max = tmp;
			}
		}
		lcm = gcd * (a / gcd) * (b / gcd);
		printf("%lld\n", lcm);
	}
	return 0;
}