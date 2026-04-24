#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int A, B;
	scanf("%d %d", &A, &B);
	if (A > B)
	{
		printf(">\n");
		return 0;
	}
	if (A < B)
	{
		printf("<\n");
		return 0;
	}
	if (A == B)
	{
		printf("==\n");
		return 0;
	}
	return 0;
}