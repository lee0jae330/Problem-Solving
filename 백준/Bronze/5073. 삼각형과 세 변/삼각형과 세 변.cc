#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int a, b, c;
	while (1)
	{
		scanf("%d %d %d", &a, &b, &c);
		if (a == 0 && b == 0 && c == 0)
			break;
		int temp = (a > b) ? a : b;
		int A = (a < b) ? a : b;
		int C = (temp > c) ? temp : c;
		int B = (temp < c) ? temp : c;
		if (C >= A + B)
			printf("Invalid\n");
		else
		{
			if (A == B && A == C)
				printf("Equilateral\n");
			if (A == B && A != C)
				printf("Isosceles\n");
			if (A == C && A != B)
				printf("Isosceles\n");
			if (B == C && A != B)
				printf("Isosceles\n");
			else if (A != B && A != C && B != C)
				printf("Scalene\n");
		}
	}
	return 0;
}