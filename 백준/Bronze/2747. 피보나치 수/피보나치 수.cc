#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int an;
	int n1 = 0, n2 = 1, n3;
	scanf("%d", &an);
	for (int i = 0; i < an; i++)
	{
		n3 = n1 + n2;
		n1 = n2;
		n2 = n3;
	}
	printf("%d\n", n1);
	return 0;
}