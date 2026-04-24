#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
void swap(int* x, int* y)
{
	int tmp;
	tmp = *x;
	*x = *y;
	*y =  tmp;
}
int main(void)
{
	int a = 1, b = 0, c = 0;
	char cupswap[51] = "";
	scanf("%s", cupswap);
	for (int i = 0; i < strlen(cupswap); i++)
	{
		if (cupswap[i] == 'A')
			swap(&a, &b);
		else if (cupswap[i] == 'B')
			swap(&b, &c);
		else
			swap(&a, &c);
	}
	if (a == 1)
		printf("1\n");
	if (b == 1)
		printf("2\n");
	if (c == 1)
		printf("3\n");
	return 0;
}