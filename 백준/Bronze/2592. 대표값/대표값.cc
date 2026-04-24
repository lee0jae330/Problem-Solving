#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int arr[10];
	for (int i = 0; i < 10; i++)
		scanf("%d", &arr[i]);
	int avg;
	int sum = 0;
	for (int i = 0; i < 10; i++)
		sum += arr[i];
	avg = sum / 10;
	int mode,freq, count = 1;
	for (int i = 0; i < 10; i++)
	{
		freq = 1;
		for (int j = i + 1; j < 10; j++)
		{
			if (arr[i] == arr[j])
				freq += 1;
		}
		if (freq >= count)
		{
			mode = arr[i];
			count = freq;
		}
	}
	printf("%d\n%d\n", avg, mode);
	return 0;
}