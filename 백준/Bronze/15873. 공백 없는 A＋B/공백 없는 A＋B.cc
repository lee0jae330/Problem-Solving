#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int n,a,b;
	scanf("%d", &n);
	if (n / 100 == 0)
	{
		a = n / 10;
		b = n % 10;
		printf("%d\n", a + b);

	}
	if (n / 100 ==1 &&n/1000==0)
	{
		a = n / 10;
		b = n % 10;
		printf("%d\n", a + b);

	}
	if (n / 100 > 1 && n / 1000 == 0)
	{
		a = n / 100;
		b = n % 100;
		printf("%d\n", a + b);

	}
	if (n / 1000 == 1)
	{
		a = n / 100;
		b = n % 100;
		printf("%d\n", a + b);


	}
	return 0;
	
}