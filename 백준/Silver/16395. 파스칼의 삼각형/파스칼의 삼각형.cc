#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
double fact(int n)
{
	double x = 1;
	for (int i = 1; i <= n; i++)
		x *= i;
	return x;
}
int main(void)
{
	int n, k;
	scanf("%d %d", &n, &k);
	printf("%.lf\n", fact(n - 1) / fact(n - k ) / fact(k - 1));
	return 0;
}