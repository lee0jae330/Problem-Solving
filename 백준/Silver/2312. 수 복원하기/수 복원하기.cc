#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int arr[10000] = { 0, };
		int index = 0;
		int num;
		int count = 0;
		scanf("%d", &num);
		for (int j = 2; j <= num; j++)
		{
			if (num % j == 0)
			{
				if (arr[index] == 0)
				{
					arr[index] = j;
					count++;
				}
				else
				{
					index++;
					arr[index] = j;
					if (arr[index] == arr[index - 1])
					{
						count++;
					}
					else
					{
						printf("%d %d\n", arr[index - 1], count);
						count = 1;
					}
				}
				num /= j;
				j = 1;
				if (num == 1)
				{
					printf("%d %d\n", arr[index], count);
				}
			}
		}

	}
	return 0;
}