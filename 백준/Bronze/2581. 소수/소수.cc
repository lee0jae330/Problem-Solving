#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int arr[10000] = { 0, };
int main(void)
{
	int a, b,count;
	int index = 0;
	int number = 0;
	scanf("%d", &a);
	scanf("%d", &b);
	for (int i = a; i <= b; i++)
	{
		if (i == 1)
			continue;
		count = 0;
		for (int j = 2; j < i; j++)
		{
			if (i % j == 0)
				count++;
		}
		if (count == 0)
		{
			arr[index] = i;
			index++;
			number++;
		}
	}
	long long sum = 0;
	if (number > 0)
	{
		for (int i = 0; i < number; i++)
			sum += arr[i];
		printf("%lld\n%d\n", sum, arr[0]);
	}
	else
		printf("-1\n");
	return 0;
}