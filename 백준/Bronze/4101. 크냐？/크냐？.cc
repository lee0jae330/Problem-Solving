#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int a, b;
	while (1)
	{
		scanf("%d %d", &a, &b);
		if (a == b && a == 0)
			break;
		if (a > b)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}