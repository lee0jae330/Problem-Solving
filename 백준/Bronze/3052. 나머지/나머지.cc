#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int arr[50] = { 0, };
	int count = 0;
	for (int i = 0; i < 10; i++)
	{
		int num;
		scanf("%d", &num);
		arr[num % 42] = 1;
	}
	for (int i = 0; i < 50; i++)
	{
		if (arr[i] == 1)
			count++;
	}
	printf("%d\n", count);
	return 0;
}