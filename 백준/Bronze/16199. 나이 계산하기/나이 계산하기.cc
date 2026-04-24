#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int y1, m1, d1, y2, m2, d2;
	scanf("%d %d %d %d %d %d", &y1, &m1, &d1, &y2, &m2, &d2);
	int maan_old, old, year_old;
	int a, b, c;
	a = y2 - y1;
	b = m2 - m1;
	c = d2 - d1;
	year_old = a;
	old = a + 1;
	if (a > 0)
	{
		if (b >0)
		{
			maan_old = a;

		}
		else if (b == 0)
		{
			if (c >= 0)
			{
				maan_old = a;

			}
			else
			{
				maan_old = a - 1;
			}
		}
		else
		{
			maan_old = a - 1;			
		}
	}
	else
	{
		maan_old = a;
	}
	printf("%d\n", maan_old);
	printf("%d\n", old);
	printf("%d\n", year_old);
	return 0;
	
}