#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int N;
	scanf("%d", &N);
	int q = N / 3;
	int r = N % 3;
	if (r == 0)
	{
		if (q % 2 == 0)
			printf("CY\n");
		else
			printf("SK\n");
	}
	else if (r == 1)
	{
		if (q % 2 == 0)
			printf("SK\n");
		else
			printf("CY\n");
	}
	else
	{
		if (q % 2 == 0)
			printf("CY\n");
		else
			printf("SK\n");
	}
	return 0;
}