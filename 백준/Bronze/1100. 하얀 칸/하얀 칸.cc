#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	char chess[8][9];
	int count = 0;
	for (int i = 0; i < 8; i++)
	{
		scanf("%s", chess[i]);
	}
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (i % 2 == 0)
			{
				if (j % 2 == 0)
				{
					if (chess[i][j] == 'F')
						count++;
				}
			}
			else
			{
				if (j % 2 == 1)
				{
					if (chess[i][j] == 'F')
						count++;
				}
			}
		}
	}
	printf("%d\n", count);
	return 0;
}