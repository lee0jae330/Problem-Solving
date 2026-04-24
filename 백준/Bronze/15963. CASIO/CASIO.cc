#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);
	if (n == m)
	{
		printf("%d\n", 1);
	}
	else
	{
		printf("%d\n", 0);
	}
	return 0;
}