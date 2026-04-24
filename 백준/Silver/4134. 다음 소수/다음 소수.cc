#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#define SIZE 100001
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
	scanf("%d", &N);
	getchar();
	for (int j = 0; j < N; j++)
	{
		long long int num;
		scanf("%lld", &num);
		getchar();
		long long int root;
		int input = 0;
		if (num <= 1)
		{
			printf("2\n");
		}
		else
		{
			while (1)
			{
				input = 0;
				root = sqrt(num);
				for (int n = 2; n <= root; n++)
				{
					if (num % n == 0)
					{
						num += 1;
						input = 1;
						break;
					}
				}
				if (input == 0)
					break;
			}
			printf("%lld\n", num);
		}
	}
	
	return 0;
}
