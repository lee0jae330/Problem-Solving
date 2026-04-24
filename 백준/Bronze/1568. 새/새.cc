#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	long long N;
	scanf("%lld", &N);
	int num = 1;
	int time = 0;
	while (1)
	{
		N -= num;
		if (N < 0)
		{
			N += num;
			num = 1;
			time--;
		}
		else
			num++;
		
		time++;
		if (N == 0)
			break;
		
	}
	printf("%d\n", time);
	return 0;
}