#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
int main(void)
{
	int a, b, c;
	while (1)
	{
		scanf("%d %d %d", &a, &b, &c);
		if ((a == b) && (b == c) && (c == 0))
			break;
		int temp = (a > b) ? a : b;
		int A = (a < b) ? a : b;
		int C = (temp > c) ? temp : c;
		int B = (temp < c) ? temp : c;
		if (pow(C, 2) == pow(A, 2) + pow(B, 2))
			printf("right\n");
		else
			printf("wrong\n");
	}
	return 0;
}