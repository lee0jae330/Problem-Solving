#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int T;
	scanf("%d", &T);
	int arr[100] = { 0, };
	for (int i = 0; i < T; i++)
	{
		int N;
		scanf("%d", &N);
		for (int j = 0; j < N; j++)
			scanf("%d", &arr[j]);
		int sum = 0;
		for (int j = 0; j < N; j++)
			sum += arr[j];
		printf("%d\n", sum);
	}
	return 0;
}