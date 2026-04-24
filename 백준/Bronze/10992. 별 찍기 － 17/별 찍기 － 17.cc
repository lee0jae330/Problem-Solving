#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int N;
	scanf("%d", &N);
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = N; j > i+1; j--)
			printf(" ");
		if (i == N - 1)
			for (int j = 0; j < 2 * N - 1; j++)
				printf("*");
		else
		{
			printf("*");
			for (int j = 0; j < 2 * i - 1; j++)
				printf(" ");
			if (count > 0)
				printf("*");
		}
		printf("\n");
		count++;
	}
}