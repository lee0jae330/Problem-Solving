#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
	int N, M;
	scanf("%d %d", &N, &M);
	int x = 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			printf("%d", x++);
			if (j < M - 1)
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}