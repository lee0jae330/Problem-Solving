#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int N, M;
	scanf("%d %d", &N, &M);
	if (M <= 2)
		printf("NEWBIE!\n");
	else if (2 < M && M <= N)
		printf("OLDBIE!\n");
	else
		printf("TLE!\n");
	return 0;
}