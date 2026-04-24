#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int L, P;
	scanf("%d %d", &L, &P);
	int n = L * P;
	int n1, n2, n3, n4, n5;
	scanf("%d %d %d %d %d", &n1, &n2, &n3, &n4, &n5);
	printf("%d %d %d %d %d", n1 - n, n2 - n, n3 - n, n4 - n, n5 - n);
	return 0;
}