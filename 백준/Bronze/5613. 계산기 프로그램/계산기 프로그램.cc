#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
	int a, b;
	char op;
	scanf("%d", &a);
	getchar();
	while (1)
	{
		scanf("%c", &op);
		getchar();
		if (op == '=')
			break;
		scanf("%d", &b);
		getchar();
		if (op == '+')
			a += b;
		else if (op == '-')
			a -= b;
		else if (op == '*')
			a *= b;
		else if (op == '/')
			a /= b;
	}
	printf("%d\n", a);
	return 0;
}