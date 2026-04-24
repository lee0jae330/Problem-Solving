#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int arr[9];
	for (int i = 0; i < 9; i++)
		scanf("%d", &arr[i]);
	int sum = 0;
	for (int i = 0; i < 9; i++)
		sum += arr[i];
	sum -= 100;
	int total;
	int a=-1, b=-1;
	int tmp;
	int input = -1;
	for (int i = 0; i < 9; i++)
	{
		tmp = arr[i];
		for (int j = i + 1; j < 9; j++)
		{
			total = tmp + arr[j];
			if (total == sum)
			{
				a = i;
				b = j;
				input = 0;
				break;
			}
			if (input == 0)
				break;
		}
	}
	for (int i = 0; i < 9; i++)
	{
		if (i == a || i == b)
			continue;
		else
			printf("%d\n", arr[i]);
	}
	return 0;
}