#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
long long gcd12(long long x, long long y)
{
	long long small = (x < y) ? x : y;
	long long big = (x > y) ? x : y;
	while (1)
	{
		if (big % small == 0)
			return small;
		else
		{
			long long tmp = small;
			small = big % small;
			big = tmp;
		}
	}
}
int main(void)
{
	long long gcd, lcm; // 두 수 x,y lcm= gcd *(x/gcd)*(y/gcd) 4 6 gcd=2, lcm=12 12=2*4/2*6/2
	scanf("%lld %lld", &gcd, &lcm);
	long long tmp = -1;
	tmp = lcm / gcd;
	long long sum;
	long long a=1,b=tmp/1; //12 1,12 2,6 3,4 ...
	sum = a + b;
	long long x, y;
	for (long long i = 2; i <tmp/2+1; i++)
	{
		if (tmp % i == 0)
		{
			x = i;
			y = tmp / i;
			if (x + y < sum&&gcd12(x,y)==1)
			{
				a = x;
				b = y;
				sum = a + b;
			}
		}
	}
	long long n1, n2;
	n1 = a * gcd;
	n2 = b * gcd;
	long long small = (n1 < n2) ? n1 : n2;
	long long big = (n1 > n2) ? n1 : n2;
	printf("%lld %lld\n", small, big);
	return 0;
}