#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
    int N;
	scanf("%d", &N);
	if (!(N & (N - 1)))
	{
		printf("1\n");
	}
	else
		printf("0\n");
	return 0;
}