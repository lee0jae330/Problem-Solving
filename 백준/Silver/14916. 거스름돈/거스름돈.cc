#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int N;
	scanf("%d", &N);
	if (N % 5 == 0)
		printf("%d\n", N / 5);
	else
	{
		if (N > 5) 
		{
			if (N < 10)
			{
				if (N % 2 == 0)
					printf("%d\n", N / 2);
				else
				{
					int a = N / 5;
					int tmp = N - (5 * a);
					int b = tmp / 2;
					printf("%d\n", a + b);
				}
			}
			else
			{
				int a = N / 5;
				int tmp = N - (5 * a);
				if (tmp % 2 == 0)
				{
					int b = tmp / 2;
					printf("%d\n", a + b);
				}
				else
				{
					while (1)
					{
						tmp += 5;
						a -= 1;
						if (tmp % 2 == 0)
						{
							int b = tmp / 2;
							printf("%d\n", a + b);
							break;
						}
						else
							continue;
					}
				}
			}
		}
		else
		{
			if (N == 5)
				printf("%d\n", N / 5);
			else if (N % 2 == 0)
				printf("%d\n", N / 2);
			else
				printf("-1\n");
		}
	}
	return 0;
}