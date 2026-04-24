#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int n;
	int count = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = n; j > i+1; j--)
			printf(" ");
		printf("*");
		for (int j = 0; j < 2 * i - 1; j++)
			printf(" ");
		if(count>0)
			printf("*");
		printf("\n");
		count++;
	}
	return 0;
}