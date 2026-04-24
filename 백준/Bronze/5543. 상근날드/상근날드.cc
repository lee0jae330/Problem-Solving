#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int sang, jung, ha, cola, soda;
	scanf("%d %d %d %d %d", &sang, &jung, &ha, &cola, &soda);
	int n1, n2, n3, n4, n5, n6;
	n1 = sang + cola-50;
	n2 = sang + soda-50;
	n3 = jung + cola-50;
	n4 = jung + soda-50;
	n5 = ha + cola-50;
	n6 = ha + soda-50;
	int x;
	x = (n1 < n2) ? n1 : n2;
	int y;
	y = (x < n3) ? x : n3;
	int z;
	z = (y < n4) ? y : n4;
	int i;
	i = (z < n5) ? z : n5;
	int k;
	k = (i < n6) ? i : n6;
	printf("%d\n", k);
	return 0;

}