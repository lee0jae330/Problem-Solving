#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
	while (1)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		if (a == 0 && b == 0)
			return 0;
		int num = a / b;
		int tmp = a - (num * b);
		printf("%d %d / %d\n", num, tmp, b);
	}
	return 0;
}