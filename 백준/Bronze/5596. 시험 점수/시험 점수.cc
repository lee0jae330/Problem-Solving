#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int a1, a2, a3, a4;
	int b1, b2, b3, b4;
	scanf("%d %d %d %d", &a1, &a2, &a3, &a4);
	scanf("%d %d %d %d", &b1, &b2, &b3, &b4);
	int x, y;
	x = a1 + a2 + a3 + a4;
	y = b1 + b2 + b3 + b4;
	if (x == y)
	{
		printf("%d\n", x);
		return 0;
	}
	int n;
	n = (x > y) ? x : y;
	printf("%d\n", n);

}
