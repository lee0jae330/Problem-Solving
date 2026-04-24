#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
long long fact(int n)
{
	long long result = 1;
	for (int i = 1; i <= n; i++)
		result *= i;
	return result;
}
int main(void)
{
	int T;
	scanf("%d", &T);
	int N;
	for (int i = 0; i < T; i++) 
	{
		scanf("%d", &N);
		long long tmp = 1;
		long long h = N + 1;
		for (int j = 0; j < 9; j++)
		{
			tmp *= h;
			h += 1;
		}
		tmp /= fact(9);
		printf("%lld\n", tmp);
	}
	return 0;
}