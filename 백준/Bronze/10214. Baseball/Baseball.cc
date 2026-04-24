#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
	int T;
	scanf("%d", &T);
	for (int x = 0; x < T; x++)
	{
		int Y, K, sy = 0, sk = 0;
		for (int i = 0; i < 9; i++)
		{
			scanf("%d %d", &Y, &K);
			sy += Y, sk += K;
		}
		if (sy > sk)
			printf("Yonsei\n");
		else if (sy < sk)
			printf("Korea\n");
		else
			printf("Draw\n");
	}
	return 0;
}