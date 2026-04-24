#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		int A, B, C, D, E;
		scanf("%d %d %d %d %d", &A, &B, &C, &D, &E);
		double result;
		result = A * 350.34;
		result += B * 230.90;
		result += C * 190.55;
		result += D * 125.30;
		result += E * 180.90;
		printf("$%.2lf\n", result);
	}
	return 0;
}