#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int arr[1001];

int main(void)
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	int cnt = 0;
	int order = 1;
	for (int i = 0; i < N; i++)
	{
		if (order == 1)
		{
			if (arr[i] == 0)
			{
				cnt++;
				order = 2;
			}
		}
		else if (order == 2)
		{
			if (arr[i] == 1)
			{
				cnt++;
				order = 3;
			}
		}
		else if (order == 3)
		{
			if (arr[i] == 2)
			{
				cnt++;
				order = 1;
			}
		}
	}
	printf("%d\n", cnt);
	return 0;
}