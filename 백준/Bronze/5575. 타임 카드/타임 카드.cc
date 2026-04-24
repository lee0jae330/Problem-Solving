#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int A_h, A_min, A_sec, a_h, a_min, a_sec;
	int B_h, B_min, B_sec, b_h, b_min, b_sec;
	int C_h, C_min, C_sec, c_h, c_min, c_sec;
	scanf("%d %d %d %d %d %d", &A_h, &A_min, &A_sec, &a_h, &a_min, &a_sec);
	scanf("%d %d %d %d %d %d", &B_h, &B_min, &B_sec, &b_h, &b_min, &b_sec);
	scanf("%d %d %d %d %d %d", &C_h, &C_min, &C_sec, &c_h, &c_min, &c_sec);
	int a1, a2, a3, b1, b2, b3, c1, c2, c3;
	a1 = a_h - A_h;
	a2 = a_min - A_min;
	a3 = a_sec - A_sec;
	b1 = b_h - B_h;
	b2 = b_min - B_min;
	b3 = b_sec - B_sec;
	c1 = c_h - C_h;
	c2 = c_min - C_min;
	c3 = c_sec - C_sec;
	if (a3 < 0)
	{
		a3 = a3 + 60;
		a2 = a2 - 1;
		if (a2 < 0)
		{
			a2 = a2 + 60;
			a1 = a1 - 1;

		}
	}
	if (a2 < 0 && a3>0)
	{
		a2 = a2 + 60;
		a1 = a1 - 1;

	}
	if (b3 < 0)
	{
		b3 = b3 + 60;
		b2 = b2 - 1;
		if (b2 < 0)
		{
			b2 = b2 + 60;
			b1 = b1 - 1;
		}
	}
	if (b2 < 0 && b3>0)
	{
		b2 = b2 + 60;
		b1 = b1 - 1;

	}
	if (c3 < 0)
	{
		c3 = c3 + 60;
		c2 = c2 - 1;
		if (c2 < 0)
		{
			c2 = c2 + 60;
			c1 = c1 - 1;
			
		}

	}
	if (c2 < 0 && c3>0)
	{
		c2 = c2 + 60;
		c1 = c1 - 1;
		
	}
	printf("%d %d %d\n", a1, a2, a3);
	printf("%d %d %d\n", b1, b2, b3);
	printf("%d %d %d\n", c1, c2, c3);
	return 0;
}