#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
	int a, b, n, w,x,y;
	int input = 0;
	scanf("%d %d %d %d", &a, &b, &n, &w);
	for (int i = 1; i < n; i++)
	{
		if (a * i + b * (n - i) == w)
		{
			input++;
			x = i;
			y = n - i;
		}
	}
	if (input==1)
		printf("%d %d\n", x, y);
	else
		printf("-1\n");
	return 0;
}