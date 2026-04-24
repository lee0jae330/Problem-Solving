#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int A, i;
	scanf("%d %d", &A, &i);
	printf("%.0lf\n", (double)(A * (i-1)+1));
	return 0;
}