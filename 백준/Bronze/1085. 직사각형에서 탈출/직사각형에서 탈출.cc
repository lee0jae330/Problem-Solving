#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int x, y, w, h;
	scanf("%d %d %d %d", &x, &y, &w, &h);
	int a = x;
	int b = y;
	int c = h - y;
	int d = w - x;
	int n = (a < b) ? a : b;
	int m = (n < c) ? n : c;
	int k = (m < d) ? m : d;
	printf("%d\n", k);
	return 0;
}