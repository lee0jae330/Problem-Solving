#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int n;
	scanf("%d", &n);
	int num;
	num = n * (n - 1) * (n - 2) * (n - 3) / 24;
	printf("%d\n", num);
	return 0;
}