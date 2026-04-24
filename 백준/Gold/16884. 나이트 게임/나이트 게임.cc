#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		int num;
		scanf("%d", &num);
		if (num % 2 == 0)
			printf("cubelover\n");
		else
			printf("koosaga\n");
	}
	return 0;
}