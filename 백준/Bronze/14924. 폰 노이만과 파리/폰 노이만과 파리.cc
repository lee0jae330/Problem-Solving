#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int S, T, D, F;
	scanf("%d %d %d", &S, &T, &D);
	F = T * (D / (S*2));
	printf("%d", F);
	return 0;
}