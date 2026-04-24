#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	
int num;
int main(void)
{
	int T;
	scanf("%d", &T);
	int d;
	for (int i = 0; i < T; i++)
	{	
		scanf("%d", &d);
	
		for (int j = 1; j <= d; j++)
		{
			if (d >= j + j * j)
				num = j;
		}
		printf("%d\n", num);
	}
	return 0;
}