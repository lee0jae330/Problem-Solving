#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
	unsigned long long int x, y;
	scanf("%llu %llu", &x, &y);
	unsigned long long answer = 1;
	x %= 1000000007;
	while (y != 0)
	{
		if (y & 1)
			answer = (answer * x) % 1000000007;
		y >>= 1;
		x = (x * x) % 1000000007;
	}
	printf("%llu\n", answer);
	return 0;
}
