#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<algorithm>

using namespace std;

int main(void)
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int m = max(a, b);
	m = max(m, c);
	if (m == a)
	{
		if (a - b == c)
			printf("%d-%d=%d\n", a, b, c);
		else if (b * c == a)
			printf("%d=%d*%d\n", a, b, c);
	}
	else if (m == b)
	{
		if (b - c == a)
			printf("%d=%d-%d\n", a, b, c);
		else if (a * c == b)
			printf("%d=%d/%d\n", a, b, c);
	}
	else
	{
		if (c - b == a)
			printf("%d+%d=%d\n", a, b, c);
		else if (a * b == c)
			printf("%d*%d=%d\n", a, b, c);
	}
	return 0;
}