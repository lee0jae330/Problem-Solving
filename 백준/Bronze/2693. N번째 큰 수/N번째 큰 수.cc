#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int T;
	scanf("%d", &T);
	int arr[10] = { 0, };
	int sorted_arr[10];
	int tmp;
	for (int i = 0; i < T; i++)
	{
		for (int j = 0; j < 10; j++)
			scanf("%d", &arr[j]);
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k < 9; k++)
			{
				if (arr[k] < arr[k + 1])
				{
					tmp = arr[k];
					arr[k] = arr[k + 1];
					arr[k + 1] = tmp;
				}
			}
		}
		printf("%d\n", arr[2]);
	}
	return 0;
}