#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int N, X;
	int arr[10000] = { 0, };
	scanf("%d %d", &N, &X);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	for (int i = 0; i < N; i++)
	{
		if (X > arr[i])
			printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}