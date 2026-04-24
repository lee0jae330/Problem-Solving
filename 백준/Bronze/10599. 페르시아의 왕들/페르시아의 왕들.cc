#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int a, b, c, d;
	while (1)
	{
		scanf("%d %d %d %d", &a, &b, &c, &d);
		if (a == 0 && b == 0 && c == 0 && d == 0)
			break;
		int ca = c - a;
		int da = d - a;
		int cb = c - b;
		int db = d - b;
		int max1 = (ca > da) ? ca : da;
		int min1 = (ca < da) ? ca : da;
		int max2 = (max1 > cb) ? max1 : cb;
		int min2 = (min1 < cb) ? min1 : cb;
		int max3 = (max2 > db) ? max2 : db;
		int min3 = (min2 < db) ? min2 : db;
		printf("%d %d\n", min3, max3);
	}
	return 0;
}