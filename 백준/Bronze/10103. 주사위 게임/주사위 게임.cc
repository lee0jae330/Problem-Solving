#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
	int N;
	scanf("%d", &N);
	int c = 100, s = 100;
	for (int i = 0; i < N; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		if (a > b)
			s -= a;
		else if (a < b)
			c -= b;
	}
	printf("%d\n%d\n", c, s);
	return 0;
}