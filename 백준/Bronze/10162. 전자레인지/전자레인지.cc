#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int T, A, B, C;
	scanf("%d", &T);
	A = T / 300;
	T %= 300;
	B = T / 60;
	T %= 60;
	C = T / 10;
	int x = T % 10;
	if (x == 0)
	{
		printf("%d %d %d", A, B, C);
		return 0;
	}
	else
	{
		printf("-1\n");
		return 0;
	}


	
}