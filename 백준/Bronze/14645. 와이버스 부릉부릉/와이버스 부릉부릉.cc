#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int N, K;
	scanf("%d %d", &N, &K);
	while (N != 0)
	{
		scanf("%d %d", &N, &K);
		if (N == 0)
		{
			printf("%s\n", "비와이");
			break;
		}
	}
	return 0;
}