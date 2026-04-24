#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	long long int N;
	scanf("%lld", &N);
	int count = 0;
	long long int tmp = 0;
	for (long long int i = 1;; i++)
	{
		tmp += i;
		count++;
		if (tmp > N)
			break;
	}
	printf("%d\n", count - 1);
	return 0;
}