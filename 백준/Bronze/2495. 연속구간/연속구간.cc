#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int new_arr[3] = { 0, };
	for (int i = 0; i < 3; i++)
	{
		char numbers[9]="";
		scanf("%s", numbers);
		getchar();
		int arr[9] = { 0, };
		int k = 0;
		for (int j = 0; j < 8; j++)
		{
			if (numbers[j] == numbers[j + 1])
			{
				int num = (int)numbers[j] - 48;
				arr[k] += 1;
			}
			else
				k++;
		}
		int max = arr[0];
		
		for (int j = 1; j < 9; j++)
		{
			if (max < arr[j])
				max = arr[j];
		}
		if (max == 0)
			new_arr[i] = 1;
		else
			new_arr[i] = max + 1;
	}
	for (int i = 0; i < 3; i++)
		printf("%d\n", new_arr[i]);
	return 0;
}