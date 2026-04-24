#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int n1, n2, n3, n4, n5;
	scanf("%d %d %d %d %d", &n1, &n2, &n3, &n4, &n5);
	printf("%d", ((n1 * n1) + (n2 * n2) + (n3 * n3) + (n4 * n4) + (n5 * n5)) % 10);
	return 0;
}