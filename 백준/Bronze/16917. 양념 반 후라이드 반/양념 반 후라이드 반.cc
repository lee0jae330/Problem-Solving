#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
	int A, B, C, X, Y,num,price;
	scanf("%d %d %d %d %d", &A, &B, &C, &X, &Y);
	if (A + B > 2 * C)
	{
		if (X > Y)
		{
			num = X - Y;
			price = 2 * Y * C + num * A;
			int tmp = 2 * X * C;
			if (tmp < price)
				price = tmp;
		}
		else
		{
			num = Y- X;
			price = 2 * X * C + num * B;
			int tmp = 2 * Y * C;
			if (tmp < price)
				price = tmp;
		}
	}
	else
	{
		price = A * X + B * Y;
	}
	printf("%d\n", price);
	return 0;
}
