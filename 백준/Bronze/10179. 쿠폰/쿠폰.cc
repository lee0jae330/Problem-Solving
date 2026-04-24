#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int a;
	scanf("%d", &a);
	int i;
	double price;
	for (i = 1; i <= a; i++)
	{
		scanf("%lf", &price);
		printf("$%.2lf\n", price * 0.8);
	}
	
	
}