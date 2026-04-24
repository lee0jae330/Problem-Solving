#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int arr[1000] = { 0, };
	int r_arr[1000] = { 0, };
	int N, K, count = 0;
	scanf("%d %d", &N, &K);
	for (int i = 0; i <=N; i++)
		arr[i] = 1;
	int tmp=-1;
	for (int i = 2; i <= N; i++)
	{
		for (int j = i; j <= N; j += i)
		{
			if (arr[j] == 0)
				continue;
			arr[j] = 0;
			count++;
			if (count == K)
			{
				tmp = j;
				break;
			}
		}
		if (count == K)
			break;
	}
	printf("%d\n", tmp);
	return 0;
}