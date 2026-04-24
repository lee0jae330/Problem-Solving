#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int arr[100000];
int main(void)
{
	int N, K;
	int x=0,count = 0;
	scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; i++)
	{
		if (N % i == 0)
		{
			arr[x] = i;
			count++;
			x++;
		}
	}
	if (count < K)
		printf("0\n");
	else
		printf("%d\n", arr[K-1]);

	return 0;
}