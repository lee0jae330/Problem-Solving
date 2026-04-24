#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int a1, a2, a3;
	scanf("%d %d %d", &a1, &a2, &a3);
	int sum = a1 + a2 + a3;
	if (a1 == 60 && a2 == 60&& a3==60)
	{
		printf("Equilateral\n");
	}
	if (sum == 180)
	{
		if ((a1 == a2 && a1 != a3) || (a1 == a3 && a1 != a2) || (a2 == a3 && a2 != a1))
		{
			printf("Isosceles\n");
		}
		if (a1 != a2 && a2 != a3 && a1 != a3)
		{
			printf("Scalene\n");
		}
	}
	if (sum != 180)
	{
		printf("Error\n");
		
	}
	return 0;

}