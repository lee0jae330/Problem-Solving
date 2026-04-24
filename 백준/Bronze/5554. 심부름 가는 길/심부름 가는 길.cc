#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	int x = a + b + c + d;
	int min = x / 60;
	int sec = x%60;
	printf("%d\n", min);
	printf("%d\n", sec);
	return 0;

}