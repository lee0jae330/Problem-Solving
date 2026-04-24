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
		if (name[i] == 'C' || name[i] == 'A' || name[i] == 'M' || name[i] == 'B' || name[i] == 'R' || name[i] == 'I' || name[i] == 'D' || name[i] == 'G' || name[i] == 'E')
			continue;
		else
			printf("%c", name[i]);
	}
	printf("\n");
	return 0;
}