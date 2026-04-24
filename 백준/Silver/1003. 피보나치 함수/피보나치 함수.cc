#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int T;
	scanf("%d", &T);
	int N;
	int arr[42] = { 0,1,1 };
	for (int i = 3; i < 42; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	for (int i = 0; i < T; i++)
	{
		scanf("%d", &N);
		if (N == 0)
			printf("1 0\n");
		else if (N == 1)
			printf("0 1\n");
		else
			printf("%d %d\n", arr[N - 1], arr[N]);
	}
	return 0;
}