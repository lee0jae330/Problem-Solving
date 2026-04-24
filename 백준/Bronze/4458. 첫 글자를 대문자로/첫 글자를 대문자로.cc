#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main(void)
{
	char str[1000];
	int N;
	scanf("%d", &N);
	getchar();
	for (int i = 0; i < N; i++)
	{
		fgets(str, 1000, stdin);
		str[strlen(str) - 1] = '\0';
		if (str[0] >= 65 && str[0] <= 90)
			printf("%s\n", str);
		else
		{
			str[0] -= 32;
			printf("%s\n", str);
		}
	}
	return 0;
}