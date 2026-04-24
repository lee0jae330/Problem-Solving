#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int A, B, C, D, E, F;
	scanf("%d %d %d %d %d %d", &A, &B, &C, &D, &E, &F);
	int x;
	x = A + B + C;
	int y;
	y = A + B + D;
	int z;
	z = A + C + D;
	int i;
	i = B + C + D;
	int n1, n2,n3;
	n1 = (x > y) ? x : y;
	n2 = (n1 > z) ? n1 : z;
	n3 = (n2 > i) ? n2 : i;
	int n4;
	n4 = (E > F) ? E : F;
	printf("%d", n3 + n4);
	return 0;

}