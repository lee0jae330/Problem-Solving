#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		if (N % 2 == 0)
		{
			int a = N / 2;
			for (int j = 0; j < a; j++)
				printf("* ");
			printf("\n");
			for (int j = 0; j < a; j++)
				printf(" *");
			printf("\n");
		}
		else
		{
			int tmp = N / 2 + 1;
			for (int j = 0; j < tmp; j++)
				printf("* ");
			printf("\n");
			for (int j = 0; j < tmp - 1; j++)
				printf(" *");
			printf("\n");
		}
	}
	return 0;
}