#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#define SIZE 2000002
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
	int N;
	char str[9];
	scanf("%d", &N);
	getchar();
	for (int i = N; i < SIZE; i++)
	{
		if (arr[i] == 0)
		{
			if (N <= i)
			{
				sprintf(str, "%d", i);
				if (strlen(str) == 1)
				{
					printf("%d\n", i);
					break;
				}
				else if (strlen(str) == 2)
				{
					if (str[0] == str[1])
					{
						printf("%s\n", str);
						break;
					}
				}
				else if (strlen(str) == 3)
				{
					if (str[0] == str[2])
					{
						printf("%s\n", str);
						break;
					}
				}
				else if (strlen(str) == 4)
				{
					if (str[0] == str[3] && str[1] == str[2])
					{
						printf("%s\n", str);
						break;
					}
				}
				else if (strlen(str) == 5)
				{
					if (str[0] == str[4] && str[1] == str[3])
					{
						printf("%s\n", str);
						break;
					}
				}
				else if (strlen(str) == 6)
				{
					if (str[0] == str[5] && str[1] == str[4] && str[2] == str[3])
					{
						printf("%s\n", str);
						break;
					}
				}
				else if (strlen(str) == 7)
				{
					if (str[0] == str[6] && str[1] == str[5] && str[2] == str[4])
					{
						printf("%s\n", str);
						break;
					}
				}
			}
		}
	}
	return 0;
}