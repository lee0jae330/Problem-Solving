#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int N;
	scanf("%d", &N);
	int a, b, c, count = 0;
	if (N < 10)
		{
			a = 0;
			b = N;
			c = a + b;
			if (c >= 10)
				c %=10;
			while (1)
			{
				if (10 * b + c != N)
				{
					a = b;
					b = c;
					c = a + b;
					if (c >= 10)
						c %= 10;
					count++;
					
				}
				else
				{
					count++;
					break;
				}
			}
			printf("%d\n", count);
		}
	else
		{
			a = N / 10;
			b = N % 10;
			c = a + b;
			if (c > 10)
				c %= 10;
			while (1)
			{
				if (10 * b + c != N)
				{
					a = b;
					b = c;
					c = a + b;
					if (c >= 10)
						c %= 10;
					count++;
				}
				else
				{
					count++;
					
					break;
				}
			}
			printf("%d\n", count);
		}
	
	
	return 0;
}