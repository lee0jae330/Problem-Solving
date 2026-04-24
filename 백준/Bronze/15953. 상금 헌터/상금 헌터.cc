#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int a, b, money=0;
		scanf("%d %d", &a, &b);
		if (a == 1)
			money += 5000000;
		else if (1 < a&&a < 4)
			money += 3000000;
		else if (3 < a && a < 7)
			money += 2000000;
		else if (6 < a && a < 11)
			money += 500000;
		else if (10 < a && a < 16)
			money += 300000;
		else if (15 < a && a < 22)
			money += 100000;
		if (b == 1)
			money += 5120000;
		else if (1 < b&&b < 4)
			money += 2560000;
		else if (3 < b && b < 8)
			money += 1280000;
		else if (7 < b && b < 16)
			money += 640000;
		else if (15 < b && b < 32)
			money += 320000;
		printf("%d\n", money);
	}
	return 0;
}
