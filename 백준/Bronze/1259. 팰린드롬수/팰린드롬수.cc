#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(void)
{
	char str[6];
	while (1)
	{
		scanf("%s", str);
		getchar();
		if (strlen(str) == 1 && str[0] == '0')
			break;
		if (strlen(str) == 1)
			printf("yes\n");
		else if (strlen(str) == 2)
		{
			if (str[0] == str[1])
				printf("yes\n");
			else
				printf("no\n");
		}
		else if (strlen(str) == 3)
		{
			if (str[0] == str[2])
				printf("yes\n");
			else
				printf("no\n");
		}
		else if (strlen(str) == 4)
		{
			if (str[0] == str[3] && str[1] == str[2])
				printf("yes\n");
			else
				printf("no\n");
		}
		else
		{
			if (str[0] == str[4] && str[1] == str[3])
				printf("yes\n");
			else
				printf("no\n");
		}
	}
	return 0;
}