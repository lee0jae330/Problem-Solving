#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int total;
	scanf("%d", &total);
	int arr[9] = { 0, };
	for (int i = 0; i < 9; i++)
		scanf("%d", &arr[i]);
	int sum = 0;
	for (int i = 0; i < 9; i++)
		sum += arr[i];
	printf("%d\n", total - sum);
	return 0;
}