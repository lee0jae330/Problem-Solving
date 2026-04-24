#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int N;
	scanf("%d", &N);
	int	money, quater, dime, nickel, penny;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &money);
		int tmp;
		quater = money / 25;
		tmp = money - 25*quater;
		dime = tmp / 10;
		tmp -= 10*dime;
		nickel = tmp / 5;
		penny = tmp % 5;
		printf("%d %d %d %d\n", quater, dime, nickel, penny);
	}
	return 0;
}