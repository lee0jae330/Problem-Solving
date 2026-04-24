#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int a1, a2, a3, a4, a5;
	scanf("%d %d %d %d %d", &a1, &a2, &a3, &a4, &a5);
	if (a1 < 40)
	{
		a1 = 40;
	}
	if (a2 < 40)
	{
		a2 = 40;
	}
	if (a3 < 40)
	{
		a3 = 40;
	}
	if (a4 < 40)
	{
		a4 = 40;
	}
	if (a5 < 40)
	{
		a5 = 40;
	}
	printf("%d\n", (a1 + a2 + a3 + a4 + a5) / 5);
	return 0;
}