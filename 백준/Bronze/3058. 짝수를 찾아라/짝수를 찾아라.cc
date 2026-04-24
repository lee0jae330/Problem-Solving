#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int arr[7];
int even[7];
int main(void)
{
	int T;
	int sum = 0;
	int k = 0;
	int tmp, count=0;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		for (int j = 0; j < 7; j++)
			scanf("%d", &arr[j]);
		for (int j = 0; j < 7; j++)
		{
			if (arr[j] % 2 == 0)
			{
				sum += arr[j];
				even[k] = arr[j];
				k++;
			}
		}
		tmp = even[0];
		for (int j = 0; j < k; j++)
		{
			if (even[j] < tmp)
				tmp = even[j];
		}
		printf("%d %d\n", sum, tmp);
		sum = 0;
		k = 0;
	}
	return 0;
}