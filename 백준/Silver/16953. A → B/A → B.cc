#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
	int A, B;
	scanf("%d %d", &A, &B);
	int count = 0;
	while (1)
	{
		if (A > B)
		{
			printf("-1\n");
			break;
		}
		if (A == B)
		{
			printf("%d\n", count + 1);
			break;
		}
		if (B % 2 == 0)
		{
			B /= 2;
		}
		else if (B % 10 == 1)
		{
			B /= 10;
		
		}
		else
		{
			printf("-1\n");
			break;
		}
		count++;
	}
	return 0;
}