#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int n, result = 0;
	while (scanf("%d", &n) !=EOF)
		if (n > 0)
			result++;
	printf("%d\n", result);
	return 0;
}