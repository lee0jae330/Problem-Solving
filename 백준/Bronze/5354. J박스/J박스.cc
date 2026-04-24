#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		int N;
		scanf("%d", &N);
		for (int j = 0; j < N; j++)
		{
			if (j == 0 || j == N - 1)
			{
				for (int k = 0; k < N; k++)
				{
					printf("#");
				}
			}
			else
			{
				for (int k = 0; k < N; k++)
				{
					if (k == 0 || k == N - 1)
						printf("#");
					else
						printf("J");
				}
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}