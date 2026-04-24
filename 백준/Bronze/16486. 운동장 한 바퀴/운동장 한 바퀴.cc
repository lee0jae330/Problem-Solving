#define _CRT_SECURE_NO_WARNINGS
#define Pi 3.141592
#include<stdio.h>
int main(void)
{
	double d1, d2;
	scanf("%lf %lf", &d1, &d2);
	printf("%.6lf\n", (d1 * 2.0) + (2.0 * d2 * Pi));
	return 0;
}