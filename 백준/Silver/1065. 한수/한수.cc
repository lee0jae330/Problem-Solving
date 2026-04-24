#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int N, a, b, c, d,count=0;
	scanf("%d", &N);
	if (N < 100)
		count = N;
	else
	{
		count = 99;
		for (int i = 100; i <= N; i++)
		{
			int tmp = i;
			c = tmp % 10;
			tmp /= 10;
			b = tmp % 10;
			a = tmp / 10;
			if (b - a == c - b)
				count++;
		}
	}
	printf("%d\n", count);
	return 0;
}