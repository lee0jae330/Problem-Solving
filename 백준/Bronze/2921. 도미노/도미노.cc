#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int N;
	scanf("%d", &N);
	int a;
	int total = 0;
	for (int i = 1; i <= N; i++)
	{
		a = i;
		for (int j = 0; j <= i; j++)
		{
			total += a;
			a++;
		}
	}
	printf("%d\n", total);
	return 0;
}