#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
int main(void)
{
	int l, h, a;
	scanf("%d %d %d", &l, &h, &a);
	double n, t1, t2;
	n = sqrt((pow(l,2) /(h*h+ a*a)));
	t1 = h *  n;
	t2 = a *  n;
	printf("%d %d", (int)t1, (int) t2);
	return 0;
}