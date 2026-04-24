#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
int main(void)
{
	double R, C, N;
	scanf("%lf %lf %lf", &R, &C, &N);
	double a;
	a = ceil(R / N) * ceil(C / N);
	printf("%.0lf\n", a);
	return 0;

}