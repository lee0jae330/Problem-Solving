#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int K, N, M;
	scanf("%d %d %d", &K, &N, &M);
	int money;
	money = K * N - M;
	if (money < 0)
	{
		money = 0;
	}
	printf("%d\n", money);
	return 0;
}