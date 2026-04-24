#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int x, y, z, i;
	x = (a > b) ? a : b;
	y=(a > b) ? b : a;
	z = (x > c) ? x : c;
	i = (x > c) ? c : x;
	if (y > i)
	{
		printf("%d %d %d", i, y, z);
		return 0;
	}
	else
	{
		printf("%d %d %d", y, i, z);
		return 0;

	}
	return 0;
}