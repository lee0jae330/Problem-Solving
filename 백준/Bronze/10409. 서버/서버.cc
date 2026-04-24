#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int arr[51];

int main(void)
{
	int N, T;
	scanf("%d %d", &N, &T);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	int idx = 0;
	int cnt = 0;
	while (1)
	{
		if (T >= arr[idx])
		{
			T -= arr[idx];
			cnt++;
			idx++;
		}
		else
			break;
		if (idx >= N)
			break;
	}
	printf("%d\n", cnt);
	return 0;
}