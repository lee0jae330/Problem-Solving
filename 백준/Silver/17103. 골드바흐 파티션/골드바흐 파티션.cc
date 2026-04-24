#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define SIZE 1000002
int arr[SIZE] = { 0, };
int main(void)
{
	arr[0] = 1, arr[1] = 1;
	for (int i = 2; i < SIZE / i; i++)
	{
		if (arr[i] == 1)
			continue;
		for (int j = i * i; j < SIZE; j += i)
		{
			if (j % i == 0)
				arr[j] = 1;
		}
	}
	int num;
	int N;
	scanf("%d", &N);
	getchar();
	for(int x=0;x<N;x++)
	{
		int count = 0;
		scanf("%d", &num);
		getchar();
		for (int i = 2; i < num/2+1; i++)
		{
			if (arr[i] == 0)
			{
				int tmp = num - i;
				if (arr[tmp] == 0)
					count++;
			}
		}
		printf("%d\n", count);
	}
	return 0;
}