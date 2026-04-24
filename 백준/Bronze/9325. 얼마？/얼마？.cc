#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		int car;
		int N;
		scanf("%d", &car);
		scanf("%d", &N);
		for (int j = 0; j < N; j++)
		{
			int num, pr;
			scanf("%d %d", &num, &pr);
			car += (num * pr);
		}
		printf("%d\n", car);
	}
	return 0;
}