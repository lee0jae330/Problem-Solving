#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int N;
	scanf("%d", &N);
	int order = 1;
	int tmp = 666;
	int num;
	int count;
	if (N == 1)
	{
		printf("%d\n", 666);
	}
	else
	{
		while (1)
		{
			count = 0;
			tmp++;
			num = tmp;
			while (num > 0)
			{
				int modd = num % 10;
				if (modd == 6)
				{
					count++;
					num /= 10;
				}
				else if (count < 3)
				{
					num /= 10;
					count = 0;
				}
				else if (count >= 3)
				{
					num /= 10;
				}
			}
			if (count >= 3)
				order++;
			if (order == N)
			{
				printf("%d\n", tmp);
				break;
			}
		}
	}
	return 0;
}