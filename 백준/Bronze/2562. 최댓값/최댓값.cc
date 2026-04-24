#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int arr[9];
	for (int i = 0; i < 9; i++)
		scanf("%d", &arr[i]);
	int tmp_arr[9];
	for (int i = 0; i < 9; i++)
		tmp_arr[i] = arr[i];
	int max = arr[0];
	for (int i = 0; i < 9; i++)
		if (arr[i] > max)
			max = arr[i];
	int real_max = 0;
	for (int i = 0; i < 9; i++)
		if (tmp_arr[i] == max)
			real_max = i+1;
	printf("%d\n%d\n", max, real_max);
	return 0;
}