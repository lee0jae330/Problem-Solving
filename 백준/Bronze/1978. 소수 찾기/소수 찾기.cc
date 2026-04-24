#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int arr[102] = { 0, };
	int N, tmp = 0, count = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	for (int i = 0; i < N; i++)
	{
		tmp = 0;
		for (int j = 2; j < arr[i]; j++)
		{
			if (arr[i] % j == 0)
			{
				tmp = 1;
				break;
			}
		}
		if (tmp == 0&&arr[i]!=1)
			count++;
	}
	printf("%d\n", count);
	return 0;
}