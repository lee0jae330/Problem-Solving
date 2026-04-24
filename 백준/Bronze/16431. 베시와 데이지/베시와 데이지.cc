#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int bx, by, dx, dy, jx, jy;
	scanf("%d %d %d %d %d %d", &bx, &by, &dx, &dy, &jx, &jy);
	int a = bx - jx;
	int A = (a > 0) ? a : -a;
	int b = by - jy;
	int B = (b > 0) ? b : -b;
	int c = dx - jx;
	int C = (c > 0) ? c : -c;
	int d = dy - jy;
	int D = (d > 0) ? d : -d;
	int bessie_time, daisy_time;
	daisy_time = C + D;
	if (A >= B)
	{
		bessie_time = A;

	}
	else
	{
		bessie_time = B;

	}
	if (bessie_time < daisy_time)
	{
		printf("bessie\n");

	}
	else if (bessie_time == daisy_time)
	{
		printf("tie\n");

	}
	else
	{
		printf("daisy\n");

	}
	return 0;
}