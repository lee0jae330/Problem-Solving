#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int x, y;
	scanf("%d %d", &x, &y);
	if (x > 0 && y > 0)
	{
		printf("1\n");
	}
	else if (x > 0 && y < 0)
	{
		printf("4\n");
	}
	else if (x < 0 && y>0)
	{
		printf("2\n");
	}
	else if (x < 0 && y < 0)
	{
		printf("3\n");
	}
}