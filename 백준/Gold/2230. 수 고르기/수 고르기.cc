#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
long long int arr[100001];
long long int gap[100001];
int compare(const void* a, const void* b)
{
	long long int x = *(long long int*)a;
	long long int y = *(long long int*)b;
	if (x < y)
		return -1;
	else if (x > y)
		return 1;
	return 0;
}

int main(void)
{
	long long int N, M;
	scanf("%lld %lld", &N, &M);
	for (long long int i = 0; i < N; i++)
		scanf("%lld", &arr[i]);
	qsort(arr, N, sizeof(long long int), compare);
	long long int start = 0, end =0;
	long long int index = 0;
	while (start<=end&&end<N) //1 3 5
	{
		if (arr[end] - arr[start] >= M)
		{
			gap[index] = arr[end] - arr[start];
			index++;
			if (start == end)
			{
				end++;
				if (end == N)
					break;
			}
			else
				start++;
		}
		else
		{
			end++;
			if (end == N)
				break;
		}
		
	}
	qsort(gap, index, sizeof(long long int), compare);
	printf("%lld\n", gap[0]);
	return 0;
}