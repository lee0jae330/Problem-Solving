#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
char str[16][30] = { "VVV딸기","VV딸기V","VV딸기딸기","V딸기VV","V딸기V딸기","V딸기딸기V","V딸기딸기딸기","딸기VVV", "딸기VV딸기","딸기V딸기V","딸기V딸기딸기","딸기딸기VV","딸기딸기V딸기","딸기딸기딸기V","딸기딸기딸기딸기" };

int main(void)
{
	int T;
	scanf("%d", &T);
	getchar();
	for (int i = 0; i < T; i++)
	{
		int N;
		scanf("%d", &N);
		getchar();
		if (N < 16)
		{
			printf("%s\n", str[(N % 16) - 1]);
		}
		else
		{
			N--;
			int num = N / 14;
			if (N == num * 14)
			{
				if (num % 2 == 0)
					printf("%s\n", str[0]);
				else
					printf("%s\n", str[14]);
			}
			else
			{
				if (num % 2 == 0)
					printf("%s\n", str[N % 14]);
				else
					printf("%s\n", str[14 - (N % 14)]);
			}
		}
	}
	return 0;
}