#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

int main(void)
{
	int A, B, C, D;
	scanf("%d %d %d %d", &A, &B, &C, &D);
	int n=0, m=0;
	int b=B, d=D;

	while (b!=0)
	{
		b /= 10;
		n++;
	}
	long long int tmp = A * pow(10, n);
	tmp += B;

	while (d != 0)
	{
		d /= 10;
		m++;
	}
	long long int tmp1 = C * pow(10, m);
	tmp1 += D;
	long long int sum = tmp + tmp1;
	printf("%lld\n", sum);
	return 0;
	
}