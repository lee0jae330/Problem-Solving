#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main(void)
{
	int N;
	char str[100];
	int score;
	int tmp;
	char oo = 'O';
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		score = 0;
		tmp = 0;
		scanf("%s", str);
		for (int j = 0; j < strlen(str); j++)
		{
			if (str[j] == oo)
			{
				tmp+=1;
				score += tmp;
			}
			else
				tmp = 0;
		}
		printf("%d\n", score);
	}
	return 0;
}