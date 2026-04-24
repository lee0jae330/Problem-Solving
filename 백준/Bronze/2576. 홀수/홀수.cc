#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int arr[7] = { 0, };
	for (int i = 0; i < 7; i++)
		scanf("%d", &arr[i]);
	int oddsum = 0;
	int min[7] = { 0, };
	int j = 0;
	for (int i = 0; i < 7; i++)
	{
		if (arr[i] % 2 == 1)
		{
			oddsum += arr[i];
			min[j] = arr[i];
			j++;
		}
	}
	int tmp = min[0];
	for (int k = 1; k <= j; k++)
	{
		if (tmp > min[k])
		{
			if (min[k] == 0)
				break;
			tmp = min[k];
		}
	}
	if (oddsum > 0)
	{
		printf("%d\n", oddsum);
		printf("%d\n", tmp);
	}
	else
		printf("-1\n");
	return 0;

}