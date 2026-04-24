#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int N;
	int min = 1000001;
	int max = -1000001;
	int target = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &target);
		if (target < min)
			min = target;
		if (target > max)
			max = target;
	}
	printf("%d %d\n", min, max);
	return 0;
}