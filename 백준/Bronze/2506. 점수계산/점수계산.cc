#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int K;
	scanf("%d", &K);
	int arr[100] = { 0, };
	for (int i = 0; i < K; i++)
		scanf("%d", &arr[i]);
	int point = 0;
	int tmp = 1;
	for (int i = 0; i < K; i++)
	{
		if (arr[i] == 1)
		{
			if (arr[i + 1] == 1)
				tmp++;
			else
				tmp = 1;
			point += tmp;
		}
	}
	printf("%d\n", point);
	return 0;
}