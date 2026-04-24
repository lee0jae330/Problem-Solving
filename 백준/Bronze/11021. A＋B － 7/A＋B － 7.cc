#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int N,a,b;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &a, &b);
		printf("Case #%d: %d\n", i + 1, a + b);
	}
	return 0;
}