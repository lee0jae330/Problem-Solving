#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int arr1[10] = { 0, };
	int arr2[10] = { 0, };
	for (int i = 0; i < 10; i++)
		scanf("%d %d", &arr1[i], &arr2[i]);
	int max = arr2[0] - arr1[0];
	int tmp = 0;
	int tmp1 = 0;
	for (int i = 0; i < 10; i++)
	{
		tmp += arr2[i];
		tmp1 += arr1[i];
		int r_max = tmp - tmp1;
		if (max < r_max)
			max = r_max;
	}
	printf("%d\n", max);
	return 0;
}