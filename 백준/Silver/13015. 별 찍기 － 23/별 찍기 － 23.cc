#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		printf("*");
	for (int i = 0; i < 2 * N - 3; i++)
		printf(" ");
	for (int i = 0; i < N; i++)
		printf("*");
	printf("\n");
	int a = N;
	for (int i = 0; i < N-2; i++)
	{
		a--;
		for (int j = 0; j <= i; j++)
			printf(" ");
		printf("*");
		for (int j = 0; j < N-2; j++)
			printf(" ");
		printf("*");
		for (int j = 0; j <2*a-3; j++)
			printf(" ");
		printf("*");
		for (int j = 0; j < N - 2; j++)
			printf(" ");
		printf("*\n");
	}
	for (int i = 0; i < N - 1; i++)
		printf(" ");
	printf("*");
	for (int k = 0; k < 2; k++)
	{
		for (int i = 0; i < N - 2; i++)
			printf(" ");
		printf("*");
	}
	printf("\n");
	for (int i = 0; i < N - 2; i++)
	{
		for (int j = N - 2; j > i; j--)
			printf(" ");
		printf("*");
		for (int j = 0; j < N - 2; j++)
			printf(" ");
		printf("*");
		for (int j = 0; j < 2 * a - 3; j++)
			printf(" ");
		printf("*");
		for (int j = 0; j < N - 2; j++)
			printf(" ");
		printf("*\n");
		a++;
	}
	for (int i = 0; i < N; i++)
		printf("*");
	for (int i = 0; i < 2 * N - 3; i++)
		printf(" ");
	for (int i = 0; i < N; i++)
		printf("*");
	printf("\n");
	return 0;
}