#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int a;
		scanf("%d", &a);
		int count = 0;
		for (int j = 5; j <= a; j *= 5)
		{
			count += a / j;
		}
		printf("%d\n", count);
	}
	return 0;
}