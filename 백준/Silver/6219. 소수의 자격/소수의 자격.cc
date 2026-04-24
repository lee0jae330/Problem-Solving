#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<string.h>
#define SIZE 20001
int arr[SIZE] = { 0, };
int main(void)
{
	arr[0] = 1, arr[1] = 2;
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
	int A, B, D, count = 0;
	scanf("%d %d %d", &A, &B, &D);
	for (int i = A; i <= B; i++)
	{
		if (i < SIZE)
		{
			if (arr[i] == 0)
			{
				char str[10];
				sprintf(str, "%d", i);
				for (int j = 0; j < strlen(str); j++)
				{
					if (str[j] - '0' == D)
					{
						count++;
						break;
					}
				}
			}
		}
		else
		{
			int input = 0;
			for (int j = 2; j <= sqrt(i); j++)
			{
				if (arr[j] == 0)
				{
					if (i % j == 0)
					{
						input = 1;
						break;
					}
				}
			}
			if (input == 0)
			{
				char str[10];
				sprintf(str, "%d", i);
				for (int j = 0; j < strlen(str); j++)
				{
					if (str[j] - '0' == D)
					{
						count++;
						break;
					}
				}
			}
		}
	}
	printf("%d\n", count);
	return 0;
}