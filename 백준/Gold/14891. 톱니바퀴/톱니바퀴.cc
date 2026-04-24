#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
char g1[9];
char g2[9];
char g3[9];
char g4[9];
int K;

void clock(char *str)
{
	char tmp = str[7];
	for (int i = 6; i >= 0; i--)
	{
		str[i + 1] = str[i];
	}
	str[0] = tmp;
}

void revclock(char* str)
{
	char tmp = str[0];
	for (int i = 1; i < 8; i++)
	{
		str[i - 1] = str[i];
	}
	str[7] = tmp;
}

int main(void)
{
	fgets(g1, 9, stdin);
	g1[8] = '\0';
	getchar();
	fgets(g2, 9, stdin);
	g2[8] = '\0';
	getchar();
	fgets(g3, 9, stdin);
	g3[8] = '\0'; 
	getchar();
	fgets(g4, 9, stdin);
	g4[8] = '\0';
	getchar();
	scanf("%d", &K);
	getchar();
	for (int i = 0; i < K; i++)
	{
		int num, dir;
		scanf("%d %d", &num, &dir);
		if (num == 1)
		{
			if (dir == 1)
			{
				if (g1[2] != g2[6])
				{
					if (g2[2] != g3[6])
					{
						if (g3[2] != g4[6])
							revclock(g4);
						clock(g3);
					}
					revclock(g2);
				}
				clock(g1);
			}
			else
			{
				if (g1[2] != g2[6])
				{
					if (g2[2] != g3[6])
					{
						if (g3[2] != g4[6])
							clock(g4);
						revclock(g3);
					}
					clock(g2);
				}
				revclock(g1);
			}
		}
		else if (num == 2)
		{
			if (dir == 1)
			{
				if (g2[6] != g1[2])
					revclock(g1);
				if (g2[2] != g3[6])
				{
					if (g3[2] != g4[6])
						clock(g4);
					revclock(g3);
				}
				clock(g2);
			}
			else
			{
				if (g2[6] != g1[2])
					clock(g1);
				if (g2[2] != g3[6])
				{
					if (g3[2] != g4[6])
						revclock(g4);
					clock(g3);
				}
				revclock(g2);
			}
		}
		else if (num == 3)
		{
			if (dir == 1)
			{
				if (g3[2] != g4[6])
					revclock(g4);
				if (g3[6] != g2[2])
				{
					if (g2[6] != g1[2])
						clock(g1);
					revclock(g2);
				}
				clock(g3);
			}
			else
			{
				if (g3[2] != g4[6])
					clock(g4);
				if (g3[6] != g2[2])
				{
					if (g2[6] != g1[2])
						revclock(g1);
					clock(g2);
				}
				revclock(g3);
			}
		}
		else
		{
			if (dir == 1)
			{
				if (g4[6] != g3[2])
				{
					if (g3[6] != g2[2])
					{
						if (g2[6] != g1[2])
							revclock(g1);
						clock(g2);
					}
					revclock(g3);
				}
				clock(g4);
			}
			else
			{
				if (g4[6] != g3[2])
				{
					if (g3[6] != g2[2])
					{
						if (g2[6] != g1[2])
							clock(g1);
						revclock(g2);
					}
					clock(g3);
				}
				revclock(g4);
			}
		}
	}
	int score = 0;
	if (g1[0] == '1')
		score += 1;
	if (g2[0] == '1')
		score += 2;
	if (g3[0] == '1')
		score += 4;
	if (g4[0] == '1')
		score += 8;
	printf("%d\n", score);
	return 0;
}