#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	long long int N, M;
	scanf("%lld %lld", &N, &M);
	long long int K = N - M;
	long long int five1=0, five2=0, five3=0;
	long long int two1 = 0, two2 = 0, two3 = 0;
	for (long long int i = 5; i <= N; i *= 5)
		five1 += N / i;
	for (long long int i = 5; i <= M; i *= 5)
		five2 += M / i;
	for (long long int i = 5; i <= K; i *= 5)
		five3 += K / i;
	for (long long int i = 2; i <= N; i *= 2)
		two1 += N / i;
	for (long long int i = 2; i <= M; i *= 2)
		two2 += M / i;
	for (long long int i = 2; i <= K; i *= 2)
		two3 += K / i;
	long long int fi_five = five1 - five2 - five3;
	long long int fi_two = two1 - two2 - two3;
	if (fi_five > 0 && fi_two > 0)
	{
		long long int result = (fi_two < fi_five) ? fi_two : fi_five;
		printf("%lld\n", result);
	}
	else
		printf("0\n");
	return 0;
}