#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int N;
	scanf("%d", &N);
	long long head = 0;
	long long mid= 0;
	long long rear = 1;
	
	for (int i = 0; i < N; i++)
	{
		mid =  head+ rear;
		head = rear;
		rear = mid;
	}
	printf("%lld\n", head);
	return 0;
}