#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int a;
	int n,b,c,d,e,f,g;
	d = 0;
	g = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a);
		b = a/30;
		if (a % 30 >= 0)
			b += 1;
		c = 10 * b;
		d += c;
		e = a / 60;
		if (a % 60 >= 0)
			e += 1;
		f = 15 * e;
		g += f;
	}
	if (d < g)
	{
		printf("Y %d\n", d);
	}
	if (d == g)
	{
		printf("Y M %d\n", d);
	}
	if (d > g)
	{
		printf("M %d\n", g);
	}
	return 0;
}
