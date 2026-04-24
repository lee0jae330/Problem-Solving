#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int N, M;
	scanf("%d %d", &N, &M);
	int small = (N < M) ? N : M;
	int big = (N > M) ? N : M;
	int gcd = -1;
	while (1)
	{
		if (big % small == 0)
		{
			gcd = small;
			break;
		}
		else
		{
			int tmp = small;
			small = big % small;
			big = tmp;
		}
	}
	printf("%d\n", gcd);
	return 0;
}