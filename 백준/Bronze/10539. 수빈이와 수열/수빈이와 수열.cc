#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int N;
	scanf("%d", &N);
	int a[100] = { 0 };
	int b[100] = { 0 };
	for (int i = 0; i < N; i++)
		scanf("%d", &a[i]);
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		if (i == 0)
		{
			b[0] = a[0];
		}
		else 
		{
			b[i] = (i + 1) * a[i] - sum;
		}
		sum += b[i];
	}
	for (int i = 0; i < N; i++)
		printf("%d ", b[i]);
	printf("\n");
	return 0;
}