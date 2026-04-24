#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char str[1002][30];
int compare(const void* a, const void* b)
{
	char* x = (char*)a;
	char* y = (char*)b;
	char str1[30], str2[30];
	strcpy(str1, x);
	strcpy(str2, y);
	for (int i = 0; i < strlen(x); i++)
	{
		if (str1[i] >= 65 && str1[i] <= 90)
			continue;
		else
		{
			str1[i] -= 32;
		}
	}
	for (int i = 0; i < strlen(y); i++)
	{
		if (str2[i] >= 65 && str2[i] <= 90)
			continue;
		else
		{
			str2[i] -= 32;
		}
	}
	return strcmp(str1, str2);
}
int main(void)
{
	int N;
	while (1)
	{
		scanf("%d", &N);
		if (N == 0)
			break;
		else
		{
			for (int i = 0; i < N; i++)
				scanf("%s", str[i]);
			qsort(str, N, sizeof(str[0]), compare);
			printf("%s\n", str[0]);
		}
	}
	return 0;
}