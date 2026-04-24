#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int N;
	int x, y;
	int gcd = -1;;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &x, &y);
		int big = (x > y) ? x : y;
		int small = (x < y) ? x : y;
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
		int lcd = (gcd * (x / gcd) * (y / gcd));
		printf("%d\n", lcd);
	}
	return 0;
}