#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);
	N = K / M;
	M = K % M;
	printf("%d %d", N, M);
	return 0;

}