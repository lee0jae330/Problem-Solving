#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char str[202][4];
char str1[202][4];
int compare(const void* a, const void* b)
{
	char *x = (char*)a;
	char *y = (char*)b;
	return strcmp(x, y);
}
int main(void)
{
	int T;
	scanf("%d", &T);
	int N;
	for (int i = 0; i < T; i++)
	{
		scanf("%d", &N);
		for (int j = 0; j < N;j++)
		{
			scanf("%s", &str[j]);
			getchar();
		}
		for (int j = 0; j < N; j++)
		{
			scanf("%s", &str1[j]);
			getchar();
		}
		int tmp = 0;
		qsort(str, N, sizeof(str[0]), compare);
		qsort(str1, N, sizeof(str[0]), compare);
		for (int j = 0; j < N; j++)
		{
			if (strcmp(str[j], str1[j]) != 0)
			{
				tmp = 1;
				break;
			}
		}
		if (tmp == 0)
			printf("NOT CHEATER\n");
		else
			printf("CHEATER\n");
	}
	return 0;

}