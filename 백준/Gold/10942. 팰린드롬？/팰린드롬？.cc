#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

bool palindrom[2001][2001] = { false, };
int arr[2001];

int main(void)
{
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &arr[i]);
	for (int i = 1; i <= N; i++)
		palindrom[i][i] = true;
	for (int i = 1; i <= N-1; i++)
	{
		if (arr[i] == arr[i + 1])
			palindrom[i][i + 1] = true;
	}
	for (int i = N; i >= 1; i--)
	{
		for (int j = i + 2; j <= N; j++)
		{
			if (arr[i] == arr[j] && palindrom[i + 1][j - 1])
				palindrom[i][j] = true;
		}
	}
	int tmp;
	scanf("%d", &tmp);
	for (int i = 0; i < tmp; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		if (palindrom[a][b])
			printf("1\n");
		else
			printf("0\n");
	}
	return 0;
}