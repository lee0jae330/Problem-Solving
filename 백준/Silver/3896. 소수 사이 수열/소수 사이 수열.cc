#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define SIZE 1300001
int arr[SIZE] = { 0, };
int main(void)
{
	arr[0] = 1, arr[1] = 1;
	for (int i = 2; i < SIZE / i; i++)
	{
		if (arr[i] == 1)
			continue;
		for (int j = i * i; j < SIZE; j++)
		{
			if (j % i == 0)
				arr[j] = 1;
		}
	}
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int num;
		scanf("%d", &num);
		if (arr[num] == 0)
			printf("0\n");
		else
		{
			int x, y;
			int tmp = 0;
			while (1)
			{
				if (arr[num + tmp] == 0)
				{
					x = num + tmp;
					break;
				}
				else
					tmp++;
			}
			tmp = 0;
			while (1)
			{
				if (arr[num - tmp] == 0)
				{
					y = num - tmp;
					break;
				}
				else
					tmp++;
			}
			printf("%d\n", x - y);
		}
	}
	return 0;
}