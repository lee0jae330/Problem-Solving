#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
	int A, B;
	scanf("%d %d", &A, &B);
	int chick;
	scanf("%d", &chick);
	if (A + B >= chick * 2)
		printf("%d\n", (A + B) - chick * 2);
	else
		printf("%d\n", A + B);
	return 0;
}