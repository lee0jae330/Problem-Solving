#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int S, K, H;
	scanf("%d %d %d", &S, &K, &H);
	int total = S + K + H;
	if (total >= 100)
	{
		printf("OK\n");

	}
	else
	{
		if (S < K && S < H)
		{
			printf("Soongsil\n");
		}
		else if (K < S && K < H)
		{
			printf("Korea\n");
		}
		else if (H < S && H < K)
		{
			printf("Hanyang\n");
		}
	}
	return 0;
}