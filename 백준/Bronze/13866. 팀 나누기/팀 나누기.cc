#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int A, B, C, D;
	scanf("%d %d %d %d", &A, &B, &C, &D);
	int a, b, c, d,e,f;
	a = A + B;
	b = C + D;
	c = A + C;
	d = B + D;
	e = A + D;
	f = B + C;
	int i, j, k;
	i = ((a - b)>0)?(a-b):-(a-b);
	j = ((c - d)>0)?(c-d):-(c-d);
	k = ((e - f)>0)?(e-f):-(e-f);
	int n;
	n = (i < j) ? i : j;
	int m = (n < k) ? n : k;
	printf("%d\n",m);

	
	
}