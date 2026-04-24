#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int N;
	scanf("%d", &N);
	int a;
	int n1=0, n2=0;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &a);
		if (a == 1)
			n1++;
		else
			n2++;
	}
	if (n1 > n2)
		printf("Junhee is cute!\n");
	else
		printf("Junhee is not cute!\n");
	return 0;
}