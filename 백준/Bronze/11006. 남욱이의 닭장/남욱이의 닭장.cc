#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		int num = 0;
		while (1)
		{
			if (a == num + 2 * (b - num))
				break;
			num++;
		}
		printf("%d %d\n", num, b - num);
	}
	return 0;
}