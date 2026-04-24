#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main(void)
{
	char name[1000];
	fgets(name, 1000, stdin);
	name[strlen(name) - 1] = '\0';
	for (int i = 0; i < strlen(name); i++)
	{
		if (name[i] >= 65 && name[i] <= 90)
			printf("%c", name[i]);
	}
	printf("\n");
	return 0;
}