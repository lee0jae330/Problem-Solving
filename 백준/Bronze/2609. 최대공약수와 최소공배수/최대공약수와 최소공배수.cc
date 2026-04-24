#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int x, y;
	scanf("%d %d", &x, &y);
	int big = (x > y) ? x : y;
	int small = (x < y) ? x : y;
	int gcd;
	while (1)
	{
		if (big % small == 0)
		{
			gcd = small;
			break;
		}
		else
		{
			int tmp;
			tmp = small;
			small = big % small;
			big = tmp;
		}
	}
	int lcd = gcd * (x / gcd) * (y / gcd);
	printf("%d\n%d\n", gcd, lcd);
	return 0;
}