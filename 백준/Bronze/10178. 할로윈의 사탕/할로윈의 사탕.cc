#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		int c, v;
		scanf("%d %d", &c, &v);
		int num = c / v;
		int dad = c - (num*v);
		printf("You get %d piece(s) and your dad gets %d piece(s).\n",num,dad);
	}
	return 0;
}