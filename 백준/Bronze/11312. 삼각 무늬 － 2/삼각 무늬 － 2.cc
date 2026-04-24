#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int N;
	scanf("%d", &N);
	long long a, b;
	for (int i = 0; i < N; i++)
	{
		scanf("%lld %lld", &a, &b);
		printf("%lld\n", (a / b) * (a / b));

	}	
	return 0;
}