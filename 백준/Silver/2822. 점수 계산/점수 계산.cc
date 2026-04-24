#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int arr[8],tmp;
	int index[8];
	for (int i = 0; i < 8; i++)
		scanf("%d", &arr[i]);
	for (int i = 0; i < 8; i++)
		index[i] = arr[i];
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
	int sum = 0;
	int num[5] = { 0, };
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (arr[i] == index[j])
				num[i] = j;
		}
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (num[j] > num[j + 1])
			{
				tmp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = tmp;
			}
		}
	}
	
	for (int i = 0; i < 5; i++)
		sum += arr[i];
	printf("%d\n",sum);
	for (int i = 0; i < 5; i++)
		printf("%d ", num[i]+1);
	printf("\n");
	return 0;
}