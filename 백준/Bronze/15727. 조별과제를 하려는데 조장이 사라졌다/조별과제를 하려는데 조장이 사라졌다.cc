#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
int main(void)
{
	double L, t;
	t = 5;
	scanf("%lf", &L);
	double min;
	min = ceil(L / t);
	printf("%.0lf", min);
	return 0;
}
