#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int C, K, P;
	scanf("%d %d %d", &C, &K, &P);
	int num = 0;
	for (int i = 1; i <= C; i++)
	{
		num += K * i + P * i * i;
	}
	printf("%d\n", num);
	return 0;
}