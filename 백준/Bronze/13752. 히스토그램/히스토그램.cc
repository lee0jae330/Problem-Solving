#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int arr[100];

int main(void)
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < arr[i]; j++)
			printf("=");
		printf("\n");
	}
	return 0;
}