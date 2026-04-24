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
	while(1)
	{
		int index = 0;
		scanf("%d", &num);
		getchar();
		if (num == 0)
			return 0;
		for (int i = 2; i <= num; i++)
		{
			if (arr[i] == 0)
			{
				int tmp = num - i;
				if (arr[tmp] == 0)
				{
					index = i;
					break;
				}
			}
		}
		int n1 = index;
		int n2 = num - index;
		printf("%d = %d + %d\n",num, n1, n2);
	}
	return 0;
}