#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int arr[1000001];
int gcd(int a, int b)
{
	int small = (a < b) ? a : b;
	int big = (a > b) ? a : b;
	while (1)
	{
		if (big % small == 0)
		{
			return small;
		}
		else
		{
			int tmp = small;
			small = big % small;
			big = tmp;
		}
	}
}
int main(void)
{
	int T,N;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		long long sum = 0;
		scanf("%d", &N);
		for (int j = 0; j < N; j++)
			scanf("%d", &arr[j]);
		for (int j = 0; j < N; j++)
		{
			for (int k = j + 1; k < N; k++)
			{
				sum += gcd(arr[j], arr[k]);
			}
		}
		printf("%lld\n", sum);
	}
	return 0;
}