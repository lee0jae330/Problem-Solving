#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int arr[5];
	for (int i = 0; i < 5; i++)
		scanf("%d", &arr[i]);
	int sum = 0;
	for (int i = 0; i < 5; i++)
		sum += arr[i];
	int avg = sum / 5;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
	int middle = arr[2];
	printf("%d\n%d\n", avg, middle);
	return 0;

}