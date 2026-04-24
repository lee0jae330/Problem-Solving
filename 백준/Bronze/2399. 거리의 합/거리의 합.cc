#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int n;
	scanf("%d", &n);
	unsigned long long arr[10000] = { 0, };
	for (int i = 0; i < n; i++)
		scanf("%llu", &arr[i]);
	unsigned long long distance, big, small, tmp, sum = 0;
	for(int i=0;i<n;i++)
	{ 
		tmp = arr[i];
		for (int j = 0; j < n; j++)
		{
			big = (tmp >= arr[j]) ? tmp : arr[j];
			small = (tmp < arr[j]) ? tmp : arr[j];
			distance = big - small;
			sum += distance;
		}
	}
	printf("%llu\n", sum);
	return 0;
}