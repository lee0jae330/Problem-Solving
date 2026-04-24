#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int N;
	scanf("%d", &N);
	int V, E;
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &V, &E);
		int M = 2 - V + E;
		printf("%d\n", M);
	}
	return 0;
}