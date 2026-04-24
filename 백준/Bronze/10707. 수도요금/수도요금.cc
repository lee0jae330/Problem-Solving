#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int x, y_price, c, d, p;
	scanf("%d %d %d %d %d", &x, &y_price, &c, &d, &p);
	int x_total_price = x * p;
	int y_total_price;
	if (p > c)
	{
		int n = y_price;
		p = p - c;
		int m = p * d;
		y_total_price = n + m;
	}
	else
	{
		y_total_price = y_price;

	}
	int a;
	a = (x_total_price < y_total_price) ? x_total_price : y_total_price;
	printf("%d\n", a);

	
}