#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<algorithm>

using namespace std;

int arr[501][501];
int MAX= 0;


void first_1(int N,int M)
{
	int sum;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M-3; j++)
		{
			sum = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i][j + 3];
			MAX = max(MAX, sum);
		}
	}
}

void first_2(int N, int M)
{
	int sum;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N-3; j++)
		{
			sum = arr[j][i] + arr[j + 1][i] + arr[j + 2][i] + arr[j + 3][i];
			MAX = max(MAX, sum);
		}
	}
}

void second(int N, int M)
{
	int sum;
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < M - 1; j++)
		{
			sum = arr[i][j] + arr[i][j + 1] + arr[i + 1][j] + arr[i + 1][j + 1];
			MAX = max(MAX, sum);
		}
		
	}
}

void third_1(int N, int M)
{
	int sum;
	int tmp;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M - 2; j++)
		{
			sum = arr[i][j] + arr[i][j + 1] + arr[i][j + 2];
			if (i + 1 < N)
			{
				for (int k = 0; k < 3; k++)
				{
					tmp = sum+arr[i+1][j+k];
					MAX = max(MAX, tmp);
				}
			}
			if (i - 1 >= 0)
			{
				for (int k = 0; k < 3; k++)
				{
					tmp = sum+ arr[i - 1][j + k];
					MAX = max(MAX, tmp);
				}
			}
		}
	}
}




void third_2(int N, int M)
{
	int sum, tmp;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N - 2; j++)
		{
			sum = arr[j][i]+arr[j+1][i]+arr[j+2][i];
			if(i-1>=0)
			{
				for (int k = 0; k < 3; k++)
				{
					tmp = sum+arr[j+k][i-1];
					MAX = max(MAX, tmp);
				}
			}
			if(i+1<M)
			{
				for (int k = 0; k < 3; k++)
				{
					tmp = sum + arr[j + k][i + 1];
					MAX = max(MAX, tmp);
				}
			}
			
		}
	}
}

void fourth_1(int N, int M)
{
	int sum,tmp1,tmp2;
	for (int i = 1; i < N - 1; i++)
	{
		for (int j = 0; j < M - 1; j++)
		{
			sum = arr[i][j] + arr[i][j + 1];
			tmp1 = sum + arr[i - 1][j] + arr[i + 1][j + 1];
			tmp2 = sum + arr[i + 1][j] + arr[i - 1][j + 1];
			MAX = max(MAX, tmp1);
			MAX = max(MAX, tmp2);
		}
	}
}


void fourth_2(int N, int M)
{
	int sum, tmp1, tmp2;
	for (int i = 1; i < M - 1; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			sum = arr[j][i] + arr[j + 1][i];
			tmp1 = sum + arr[j][i - 1] + arr[j + 1][i + 1];
			tmp2 = sum + arr[j][i + 1] + arr[j + 1][i - 1];
			MAX = max(MAX, tmp1);
			MAX = max(MAX, tmp2);
		}
	}
	
}

int main(void)
{
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	
	first_1(N, M);
	first_2(N, M);
	second(N, M);
	third_1(N, M);
	third_2(N, M);
	fourth_1(N,M);
	fourth_2(N, M);
	printf("%d\n", MAX);
	return 0;
}