#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int a, b, c;
	int gap;
	int next;
	while (1)
	{
		scanf("%d %d %d", &a, &b, &c);
		if (a == 0 && b == 0 && c == 0)
			break;
		if (a + c == 2 * b)
		{
			gap = b - a;
			next = c + gap;
			printf("AP %d\n", next);
		}
		if (a * c == b * b)
		{
			gap = b / a;
			next = c * gap;
			printf("GP %d\n", next);
		}
	}
	return 0;
}