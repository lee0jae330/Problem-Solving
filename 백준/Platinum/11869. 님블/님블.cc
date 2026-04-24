#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
	int N;
	scanf("%d", &N);
	int tmp = 0;
	for (int i = 0; i < N; i++)
	{
		int num;
		scanf("%d", &num);
		tmp ^= num;
	}
	if (tmp == 0)
		printf("cubelover\n");
	else
		printf("koosaga\n");
	return 0;
}