#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int N;
	int arr[1001];
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		double avg = 0;
		double num;
		scanf("%lf", &num);
		for (int j = 0; j < num; j++)
		{
			scanf("%d", &arr[j]);
			avg += arr[j];
		}
		avg /= num;
		double count = 0;
		for (int j = 0; j < num; j++)
		{
			if (arr[j] > avg)
				count++;
		}
		double percent = count / num * 100;
		printf("%.3lf%%\n", percent);
	}	
	return 0;
}