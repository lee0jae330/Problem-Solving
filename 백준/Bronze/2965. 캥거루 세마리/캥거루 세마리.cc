#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	int A = b - a;
	int B = c - b;
	int tmp = (A > B) ? A : B;
	printf("%d\n", tmp - 1);
	return 0;
}