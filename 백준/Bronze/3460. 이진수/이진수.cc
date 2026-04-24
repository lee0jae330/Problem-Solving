#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int T , j;
	int arr[1000];
	int num;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		j = 0;
		scanf("%d", &num);
		while (num >= 2)
		{
			arr[j] = num % 2;
			num /= 2;
			j++;
		}
		arr[j] = num;
		for (int k = 0; k <= j; k++)
		{
			if (arr[k] == 1)
				printf("%d ", k);
			else
				continue;
		}
		printf("\n");
	}
	return 0;
}