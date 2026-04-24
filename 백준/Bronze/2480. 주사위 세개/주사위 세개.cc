#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int a, b, c,x ;
	scanf("%d %d %d", &a, &b, &c);
	if (a == b && b == c)
	{
		x = 10000 + 1000 * a;
		printf("%d", x);
		return 0;
	}
	if((a==b&&b!=c)||(a==c&&c!=b)||(b==c&& b!=a))
	{
		if(a==b)
		{ 
			x = 1000 + a * 100;
			printf("%d", x);
			return 0;
		}
		else if (b == c)
		{
			x = 1000 + b * 100;
			printf("%d", x);
			return 0;
		}
		else
		{
			x = 1000 + c * 100;
			printf("%d", x);
		}
	}
	if (a != b && b != c && c != a)
	{
		int n;
		n = (a > b) ? a : b;
		int m;
		m = (n > c) ? n : c;
		x = m * 100;
		printf("%d", x);
		return 0;
	}
	return 0;
}