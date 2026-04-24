#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main(void)
{
	char word[1000];
	fgets(word, 1000, stdin);
	word[strlen(word) - 1] = '\0';
	printf("%d\n", strlen(word));
	return 0;
}