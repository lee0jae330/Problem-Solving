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
	int N, K;
	scanf("%d %d", &N, &K);
	printf("%.lf\n", fact(N) / fact(N - K) / fact(K));
	return 0;
}