#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int a;
	int sum = 0;
	while (scanf("%d", &a) != EOF)
	{
		sum += a;
	}
	printf("%d\n", sum);
	return 0;
}