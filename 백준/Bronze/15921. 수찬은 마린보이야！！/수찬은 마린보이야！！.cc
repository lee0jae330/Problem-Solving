#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	double n;
	double a;
	double b = 0;
	double x;
	x = 0;
	double y;

	scanf("%lf", &n);
	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%lf", &a);
		y = a * (1/n);
		x += y;
		b += a;
		
	}
	double c;
	c = b / n;
	double percent;
	percent = c / x;
	if (n != 0 && x != 0)
	{
		printf("%.2lf\n", percent);
	}
	else if (n == 0 || x == 0)
	{
		printf("divide by zero\n");
	}


	
}