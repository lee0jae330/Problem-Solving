#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int tmp = (a > b) ? a : b;
	int tmin = (a < b) ? a : b;
	int max = (tmp > c) ? tmp : c;
	int t2min = (tmp < c) ? tmp : c;
	int min = (tmin < t2min) ? tmin : t2min;
	int mid = (tmin > t2min) ? tmin : t2min;
	int d1 = mid - min;
	int d2 = max - mid;
	if (d1 == d2)
		printf("%d\n", max + d2);
	else
	{
		if (d1 > d2)
			printf("%d\n", mid - d2);
		else
			printf("%d\n", mid + d1);
	}
	
	return 0;
}