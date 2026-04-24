#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int N, W, H, L;
	scanf("%d %d %d %d", &N, &W, &H, &L);
	int x = W / L;
	int y = H / L;
	int tmp = x * y;
	if (tmp > N)
		printf("%d\n", N);
	else if (tmp <= N)
		printf("%d\n", tmp);
	return 0;
}