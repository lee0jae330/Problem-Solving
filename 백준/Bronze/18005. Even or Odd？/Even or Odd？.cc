#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	unsigned long long a;
	scanf("%lld", &a);
	if (a % 2 == 1)
	{
		printf("0\n");
	}
	if (a % 2 == 0 && a % 4 == 2)
	{
		printf("1\n");	
	}
	if (a % 4 == 0)
	{
		printf("2\n");
	}
	return 0;
}