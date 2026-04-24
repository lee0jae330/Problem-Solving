#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	int max1 = (a > b) ? a : b;
	int max2 = (c > d) ? c : d;
	int max = (max1 > max2) ? max1 : max2;
	int min1 = (a < b) ? a : b;
	int min2 = (c < d) ? c : d; 
	int min=(min1 < min2) ? min1 : min2;
	int second_max;
	if (max == max1)
	{
		int tmp = min1;
		int tmp1 = (min1 >= c) ? min1 : c;
		second_max = (tmp1 >= d) ? tmp1 : d;
	}
	else
	{
		int tmp = min2;
		int tmp1 = (min2 > a) ? min2 : a;
		second_max = (tmp1 > b) ? tmp1 : b;
	}
	printf("%d\n", min * second_max);
	return 0;
}