#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int arr[10001];
int main(void)
{
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	int start = 0, end = 0;
	int partial_sum = 0;
	int count = 0;
	while (end <= N)
	{
		if (partial_sum >= M)
		partial_sum -= arr[start++];
		else if (partial_sum < M)
			partial_sum += arr[end++];
		
		if(partial_sum==M)
			count++;
	}
	printf("%d\n", count);
	return 0;
}