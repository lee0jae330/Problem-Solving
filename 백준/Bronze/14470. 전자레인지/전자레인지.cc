#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int A, B, C, D, E, time;
	scanf("%d %d %d %d %d", &A, &B, &C, &D, &E);
	if (A < 0)
	{
		int x = (A > 0) ? A : -A;
		time = C * x + D + B*E;

	}
	if (A == 0) 
	{
		time = D + B * E;
		
	}
	if (A > 0)
	{
		time = (B - A) * E;
	}
	printf("%d\n", time);
}