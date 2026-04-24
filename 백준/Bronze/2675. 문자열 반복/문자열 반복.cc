#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main(void)
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int num;
		char str[25];
		scanf("%d %s", &num, str);
		getchar();
		for (int j = 0; j < strlen(str); j++)
		{
			for (int k = 0; k < num; k++)
				printf("%c", str[j]);
		}
		printf("\n");
	}
	return 0;
}