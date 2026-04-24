#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);
	B =B+ C;
	A =A+ B/60;
	B = B%60;

	if (A>=24)
	{
		A = A - 24;


	}
	else
	{
		A = A + B/60;
		B = B%60;

	}

	printf("%d %d", A, B);
	return 0;

}