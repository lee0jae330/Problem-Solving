#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int N;
	scanf("%d", &N);
	int real_count = 0;
	for (int i = 1; i <= N; i++)
	{
		int a = i;
		int sum = 0;
		int count = 0;
		int tmp = a;
		while (1)
		{
			if (a < 10)
			{
				if (count == 0)
				{
					real_count++;
				}
				else
				{
					sum += a;
					if (tmp % sum == 0)
						real_count++;
				}
				break;
			}
			else
			{
				int modu = a % 10;
				sum += modu;
				a /= 10;
				count++;
			}
		}
	}
	printf("%d\n", real_count);
	return 0;
}