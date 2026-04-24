#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int p[49];
int s[49];
int copy[49];
int count = 0;
int input = 0;
int N;

void check()
{
	for (int i = 0; i < N; i++)
	{
		if (p[i] != i % 3)
		{
			input = 1;
			return;
		}
	}
}

void swap()
{
	for (int i = 0; i < N; i++)
	{
		int tmp = p[i];
		copy[s[i]] = tmp;
	}
	for (int i = 0; i < N; i++)
	{
		p[i] = copy[i];
	}
}

int main(void)
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &p[i]);
	for (int i = 0; i < N; i++)
		scanf("%d", &s[i]);
	int xx = 0;
	for (int x = 0; x < 1000000; x++)
	{
		input = 0;
		check();
		if (input == 0)
		{
			xx = 1;
			break;
		}
		swap();
		count++;
	}
	if (xx == 0)
		printf("-1\n");
	else if(xx==1)
		printf("%d\n", count);
	return 0;
}
