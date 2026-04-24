#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
	int N,cnt=0;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		int tmp = i;
		while (tmp!=0)
		{
			int num = tmp % 10;
			if (num == 3 || num == 6 || num == 9)
				cnt++;
			tmp/= 10;
		}
	}
	printf("%d\n", cnt);
}