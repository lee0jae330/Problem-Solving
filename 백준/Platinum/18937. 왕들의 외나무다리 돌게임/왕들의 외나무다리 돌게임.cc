#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
	int N;
	scanf("%d", &N);
	int sol=0;
	for (int i = 0; i < N; i++)
	{
		int num;
		scanf("%d", &num);
		num -= 2;
		sol ^= num;
	}
	char name[20];
	scanf("%s", name);
	if (name[0] == 'W')
	{
		if (sol == 0)
			printf("Blackking\n");
		else
			printf("Whiteking\n");
	}
	else
	{
		if (sol == 0)
			printf("Whiteking\n");
		else
			printf("Blackking\n");
	}
	return 0;
}