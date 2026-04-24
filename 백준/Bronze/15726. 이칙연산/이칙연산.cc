#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	double A, B, C;
	scanf("%lf %lf %lf", &A, &B, &C);
	double x = A * B / C;
	double y = A / B * C;
	double n = (x > y) ? x : y;
	printf("%d\n", (int)n);
	return 0;
}