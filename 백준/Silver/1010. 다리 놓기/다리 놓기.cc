#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
long double fact(int n)
{
	long double x = 1;
	for (int i = 1; i <= n; i++)
		x *= i;
	return x;
}
int main(void)
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		int n, m;
		scanf("%d %d", &n, &m);
		printf("%.Lf\n", fact(m) / fact(n) / fact(m - n));
	}
	return 0;
}