#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int N, M, K;
	int a;
	scanf("%d %d %d", &N, &M, &K);
	if (M >= K)
	{
		a = K + (N - M);
		printf("%d\n", a);
	}
	else
	{
		a = M + (N - K);
		printf("%d\n", a);
	}
	return 0;
}