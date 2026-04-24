#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int N;
	scanf("%d", &N);
	int a_point = 0, b_point = 0;
	for (int i = 0; i < N; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		if (a > b)
			a_point++;
		else if (a < b)
			b_point++;
		else
			continue;
	}
	printf("%d %d\n", a_point, b_point);
	return 0;
}