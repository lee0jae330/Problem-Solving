#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int arr[20001];

int main(void)
{
	int N, cnt = 0;;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
		if (i + 1 != arr[i])
			cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}