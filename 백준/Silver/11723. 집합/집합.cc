#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

#define TRUE 1
#define FALSE 0
int arr[21] = { 0, };

int main(void)
{
	int N,tmp;
	char str[100];
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%s", str);
		if (!strcmp(str, "add"))
		{
			scanf("%d", &tmp);
			if(arr[tmp]==0)
				arr[tmp] = 1;
		}
		else if (!strcmp(str, "check"))
		{
			scanf("%d", &tmp);
			if (arr[tmp] == 1)
				printf("1\n");
			else
				printf("0\n");
		}
		else if (!strcmp(str, "remove"))
		{
			scanf("%d", &tmp);
			if (arr[tmp] == 1)
				arr[tmp] = 0;
		}
		else if (!strcmp(str, "toggle"))
		{
			scanf("%d", &tmp);
			if (arr[tmp] == 1)
				arr[tmp] = 0;
			else
				arr[tmp] = 1;
		}
		else if (!strcmp(str, "all"))
		{
			for (int i = 0; i < 21; i++)
				arr[i] = 1;
		}
		else
		{
			for (int i = 0; i < 21; i++)
				arr[i] = 0;
		}
	}
	return 0;
}