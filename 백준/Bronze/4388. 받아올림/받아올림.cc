#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int N, M;
	int carry;
	int result;
	while (1)
	{
		carry = 0;
		result = 0;
		scanf("%d %d", &N, &M);
		if (N == 0 && M == 0)
			break;
		int a = N;
		int b = M;
		while (1)
		{
			if (a == 0 && b == 0)
				break;
			int n = a % 10;
			int m = b % 10;
			if (n + m + carry >= 10)
			{
				carry = 1;
				result++;
			}
			else
				carry = 0;
			a /= 10;
			b /= 10;
		}
		printf("%d\n", result);
	}
	return 0;
}