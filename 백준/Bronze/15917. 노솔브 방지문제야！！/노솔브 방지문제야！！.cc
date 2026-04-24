#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
	int T;
	scanf("%d", &T);
	getchar();
	for (int i = 0; i < T; i++)
	{
		int num;
		scanf("%d", &num);
		getchar();
		if ((num & (num - 1)) == 0)
			printf("1\n");
		else
			printf("0\n");
	}
	return 0;
}