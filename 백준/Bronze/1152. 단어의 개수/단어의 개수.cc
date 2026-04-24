#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#define MAXSTR 1000003
int main(void)
{
	char str[MAXSTR];
	int count=0;
	fgets(str, MAXSTR, stdin);
	str[strlen(str) - 1] = '\0';
	char* token;
	token = strtok(str, " ");
	while (token != NULL)
	{
		count++;
		token = strtok(NULL, " ");
	}
	printf("%d\n", count);
	return 0;
}