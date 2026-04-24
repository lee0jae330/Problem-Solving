#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int arr[1000001];

int compare(const void* a, const void* b)
{
	int x = *(int*) a;
	int y = *(int*)b;
	if (x < y)
		return -1;
	else if (x > y)
		return 1;
	return 0;
}
int main(void)
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		int n, k;
		scanf("%d %d", &n, &k);
		for (int j = 0; j < n; j++)
			scanf("%d", &arr[j]);
		qsort(arr, n, sizeof(int), compare);
		int start = 0;
		int end = n - 1;
		int x = arr[start] + arr[end];
		int tmp = abs(x - k);
		int count = 0;
		while (start < end)
		{
			int xx = arr[start] + arr[end];
			if (abs(xx - k) < tmp)
			{
				tmp = abs(xx - k);
				count = 1;
			}
			else if (abs(xx - k) == tmp)
			{
				count++;
			}
			if (xx < k)
				start++;
			else
				end--;
			
		}
		printf("%d\n", count);
	}
	return 0;
}