#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define SIZE 1000001
int arr[SIZE] = { 0, };
int prime[SIZE];
int main(void)
{
	arr[0] = 1, arr[1] = 1;
	for (int i = 2; i < SIZE / i; i++)
	{
		if (arr[i] == 1)
			continue;
		for (int j = i * i; j < SIZE; j+=i)
		{
			if (j % i == 0)
				arr[j] = 1;
		}
	}
	int index = 0;
	for (int i = 2; i < SIZE; i++)
	{
		if (arr[i] == 0)
		{
			prime[index] = i;
			index++;
		}
	}
	int N,a,b,c,d;
	scanf("%d", &N);
	if (N < 8)
		printf("-1\n");
	else if(N==8)
		printf("2 2 2 2\n");
	else
	{
		if (N % 2 == 0) //N -> 짝2 홀2 / 홀4 
		{
			a = 2, b = 2;
			N -= 4;
			for (int i = 0; i < index; i++)
			{
				c = prime[i];
				d = N - c;
				if (arr[d] == 0)
				{
					printf("%d %d %d %d\n", a, b, c, d);
					return 0;
				}
			}
		}
		else
		{
			if (N == 9)
			{
				printf("2 2 2 3\n");
				return 0;
			}
			else
			{
				a = 2, b = 3;
				N -= 5;
				for (int i = 1; i < index; i++)
				{
					c = prime[i];
					d = N - c;
					if (arr[d] == 0)
					{
						printf("%d %d %d %d\n", a, b, c, d);
						return 0;
					}
				}
			}
		}
	}
	return 0;
}