#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int N;
	long long num=0;
	char str[102];
	scanf("%d", &N);
	scanf("%s", str);
	for (int i = 0; i < N; i++)
	{
		num += str[i];
	}
	long long tmp = N * 48;
	num -= tmp;
	printf("%lld\n", num);
	return 0;
}