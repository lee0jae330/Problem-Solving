#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int t;
	int n;
	char p1, p2;
	int player1, player2;
	scanf("%d", &t);
	getchar();
	for (int i = 0; i < t; i++)
	{
		player1 = 0, player2 = 0;
		scanf("%d", &n);
		getchar();
		for (int j = 0; j < n; j++)
		{
			scanf("%c %c", &p1, &p2);
			getchar();
			if (p1 == p2)
			{
				player1 += 0;
				player2 += 0;
			}
			else
			{
				if (p1 == 'R')
				{
					if (p2 == 'S')
						player1++;
					else if (p2 == 'P')
						player2++;
				}
				else if (p1 == 'S')
				{
					if (p2 == 'P')
						player1++;
					else
						player2++;
				}
				else
				{
					if (p2 == 'R')
						player1++;
					else
						player2++;
				}
			}
		}
		if (player1 > player2)
			printf("Player 1\n");
		else if (player1 < player2)
			printf("Player 2\n");
		else
			printf("TIE\n");
	}
	return 0;
}