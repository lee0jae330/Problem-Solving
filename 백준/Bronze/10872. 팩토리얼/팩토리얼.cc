#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int N;
	scanf("%d", &N);
	int total = 1;
	for (int i = 1; i <= N; i++)
		total *= i;
	printf("%d\n", total);
	return 0;
}
