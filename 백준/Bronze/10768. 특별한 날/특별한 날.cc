#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int month, day;
	scanf("%d %d", &month, &day);
	if (month == 2 && day == 18)
	{
		printf("Special\n");
	}
	else if((month == 2 && day > 18)||month>=3)
	{
		printf("After\n");
	}
	else if ((month == 2 && day < 18)||month<=1)
	{
		printf("Before\n");

	}
}