#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int years;
	scanf("%d", &years);
	if (years % 4 == 0 && years % 100 != 0 || years % 400 == 0)
	{
		printf("1\n");
		return 0;
	}
	else
	{
		printf("0\n");
		return 0;
	}
}