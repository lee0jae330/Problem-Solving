#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define SIZE 100000
int arr[SIZE] = { 1, };
int main(void)
{
	while (1)
	{
		int N;
		scanf("%d", &N);
		if (N == -1)
			return 0;
		int index = 1;
		for (int i = 2; i < N; i++)
		{
			if (N % i == 0)
			{
				arr[index] = i;
				index++;
			}
		}
		int sum = 0;
		for (int i = 0; i < index; i++)
			sum += arr[i];
		if (sum == N)
		{
			printf("%d = ", N);
			for (int i = 0; i < index ; i++)
			{
				printf("%d ", arr[i]);
				if (i == index - 1)
					continue;
				printf("+ ");
			}
			printf("\n");
		}
		else
		{
			printf("%d is NOT perfect.\n",N);
		}
	}
	return 0;
}