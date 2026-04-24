#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define SIZE 1001
int dp[SIZE][SIZE] = { 0, };
int main(void)
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (i == j || j == 0)
			{
				dp[i][j] = 1;
				continue;
			}
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 10007;
		}
	}
	int N, K;
	scanf("%d %d", &N, &K);
	printf("%d\n", dp[N][K]);
	return 0;
}