#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#define SIZE 1000001
long long int arr[SIZE] = { 0, };
long long int prime[SIZE];
int main(void)
{
	arr[0] = 1, arr[1] = 1;
	for (int i = 2; i < SIZE / i; i++)
	{
		if (arr[i] == 1)
			continue;
		for (int j = i * i; j < SIZE; j += i)
			if (j % i == 0)
				arr[j] = 1;
	}
	int index = 0;
	for (int i = 2; i < SIZE; i++)
	{
		if (arr[i] == 0)
		{
			prime[index] = i;
			index++;
		}
	}
	long long int n, result = 1;
	scanf("%lld", &n);
	for (int i = 0; i < index; i++)
	{
		if (n % prime[i] == 0)
		{
			long long int count = 0;
			while (n % prime[i] == 0)
			{
				count++;
				n /= prime[i];
			}
			if (count == 1)
			{
				result *= prime[i] - 1;
			}
			else
			{
				result *= pow(prime[i], count-1)*(prime[i]-1);
			}
		}
		if (n == 1)
			break;
	}
	int input = 0;
	if (n >=SIZE)
		result *= (n - 1);
	printf("%lld\n", result);
	return 0;
}
