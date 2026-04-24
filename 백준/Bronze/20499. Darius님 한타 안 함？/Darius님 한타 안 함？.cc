#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int K, D, A;
	scanf("%d", &K);
	getchar();
	scanf("%d", &D);
	getchar();
	scanf("%d", &A);
	if (K + A < D || D == 0)
		printf("hasu\n");
	else
		printf("gosu\n");
	return 0;
}