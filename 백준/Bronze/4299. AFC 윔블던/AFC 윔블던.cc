#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int a, b;
	scanf("%d %d", &a, &b);
	int x, y;
	x = (a + b) / 2;
	y = (a - b) / 2;
	int n, m;
	n = (x > y) ? x : y;
	m = (x> y) ? y: x;
	if (a >= b && (a+b)%2==0)
	{
		printf("%d %d", n, m);
		return 0;
	}
	else
	{
		printf("-1\n");
		return 0;
	}
}