#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	long long n1 = 1, n2 = 0, n3 = 1;
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		n3 = n1;
		n1 = n2;
		n2 = n1 + n3;
	}
	printf("%lld\n", n2);
	return 0;
}