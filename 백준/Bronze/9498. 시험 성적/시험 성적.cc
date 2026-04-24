#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int score;
	scanf("%d", &score);
	if (90 <= score && 100 >= score)
	{
		printf("A\n");

	}
	if (80 <= score && 89 >= score)
	{
		printf("B\n");

	}
	if (70 <= score && 79 >= score)
	{
		printf("C\n");

	}
	if (60 <= score && 69 >= score)
	{
		printf("D\n");

	}
	else if( 59>= score)
	{
		printf("F\n");
	}
	return 0;
}
