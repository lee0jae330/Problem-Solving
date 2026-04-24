#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int arr[5][4] = { 0, };
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	int sum[5] = { 0, };
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4; j++)
			sum[i] += arr[i][j];
	}
	int max = sum[0];
	int num;
	for (int i = 1; i < 5; i++)
	{
		if (max < sum[i])
		{
			max = sum[i];
			num = i;
		}
	}
	if (max == sum[0])
		num = 0;
	printf("%d %d\n",num+1, max);
	return 0;
}