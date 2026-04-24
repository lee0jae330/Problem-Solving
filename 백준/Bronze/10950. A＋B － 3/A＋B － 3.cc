#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int N;
	scanf("%d", &N);
	int a, b;
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &a, &b);
		printf("%d\n", a + b);
	}
	return 0;
}