#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int N;
	scanf("%d", &N);
	int a, b;
	int count;
	for (int i = 0; i < N; i++)
	{
		count = 1;
		scanf("%d %d", &a, &b);
		int c = a * a;
		int d = b * b;
		for (int j = 0;; j++)
		{
			c -= d;
			if (c <= 0)
				break;
			count++;
		}
		printf("%d\n", count);
	}
	
	return 0;
}