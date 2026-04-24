#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	unsigned int var;
	scanf("%d", &var);
	unsigned int years;
	years = var - 1946;
	printf("%d", years);
	return 0;

}