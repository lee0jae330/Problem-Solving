#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int A, B, C, D;
	scanf("%d %d %d %d", &A, &B, &C, &D);
	C = C + D;
	B =B + C / 60;
	A = A + B / 60;
	if (A >= 24)
	{	
		A = A % 24;
	}
	B = B % 60;
	C = C % 60;
	printf("%d %d %d\n", A, B, C);
	return 0;

}
