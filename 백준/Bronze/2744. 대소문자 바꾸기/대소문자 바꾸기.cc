#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main(void)
{
	char word[1000];
	fgets(word, 1000, stdin);
	word[strlen(word) - 1] = '\0';
	for (int i = 0; i < strlen(word); i++)
	{
		if (word[i]>64&&word[i]<91)
			word[i] +=32;
		else
			word[i] -= 32;
	}
	printf("%s\n", word);
	return 0;
}