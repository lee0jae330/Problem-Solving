#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int n;
	scanf("%d", &n);
	if (n <= 5)
	{
		printf("%d\n", n);
	}
	else
	{
		if (n % 8 == 1)
		{
			printf("1\n");
		}
		if (n % 4 == 3)
		{
			printf("3\n");
		}
		if (n % 8 == 5)
		{
			printf("5\n");
		}
		if (n % 8 == 0 || n % 8 == 2)
		{
			printf("2\n");
		}
		if (n % 8 == 4 || n % 8 == 6)
		{
			printf("4\n");
		}

	}
	return 0;

}