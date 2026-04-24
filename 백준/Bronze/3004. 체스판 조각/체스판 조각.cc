#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
	int n;
	scanf("%d", &n);
	if (n % 2 == 0)
	{
		n = (n + 2) / 2;
		printf("%d", n*n);
		return 0;
	}
	else
	{
		printf("%d", (n / 2 + 1) * (n / 2 + 2));
		return 0;
	}
}