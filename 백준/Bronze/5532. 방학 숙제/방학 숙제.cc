#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
int main(void)
{
	double L, A, B, C, D;
	scanf("%lf %lf %lf %lf %lf", &L, &A, &B, &C, &D);
	double x, y;
	x = ceil((A / C));
	y = ceil((B / D));
	double n, m;
	n = L - x;
	m = L - y;
	double k;
	k = (n < m) ? n : m;
	printf("%.0lf\n", k);
	return 0;
}