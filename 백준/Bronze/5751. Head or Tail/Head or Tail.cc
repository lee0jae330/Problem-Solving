#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	while (1)
	{
		int N;
		scanf("%d", &N);
		if (N == 0)
			break;
		int mary = 0, john = 0;
		int a;
		for (int i = 0; i < N; i++)
		{
			scanf("%d", &a);
			if (a == 0)
				mary++;
			else
				john++;
		}
		printf("Mary won %d times and John won %d times\n", mary, john);
	}
	return 0;
}