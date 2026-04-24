#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#define MAXSTR 1000001
int main(void)
{
	char str[MAXSTR];
	int arr[26] = { 0, };
	fgets(str, MAXSTR, stdin);
	str[strlen(str) - 1] = '\0';
	for (int i = 0; str[i]!='\0'; i++)
	{
		if ('a' <= str[i])
			str[i] -= 32;
		int num = str[i] - 'A';
		arr[num]++;
	}
	int max = 0;
	char c = '?';
	for (int i = 0; i < 26; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			c = i;
		}
		else if (arr[i] == max)
			c = '?';
	}
	if (c == '?')
		printf("%c\n", c);
	else
		printf("%c\n", c + 65);
	return 0;
}