#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int N, K;
	scanf("%d %d", &N, &K);
	int arr[20][20] = { 0, };
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[0][i]);
		getchar();
	}
	int count = 0;
	for (int i = 1; i <= K; i++)
	{
		for (int j = 0; j < N-count; j++)
			arr[i][j] = arr[i - 1][j + 1] - arr[i - 1][j];
		count++;
	}
	for (int i = 0; i < N - count; i++)
	{	
		if (i < N - count - 1)
			printf("%d,", arr[K][i]);
		else
			printf("%d", arr[K][i]);
	}
	printf("\n");
	return 0;
	
}