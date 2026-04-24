#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
	char str[52], str1[52];
	scanf("%s", &str);

	strcpy(str1, str);
	int minus = 0,plus=0;
	int tmp=1;
	int i = 0;
	if (str[0] == '-')
	{
		str[0] = '0';
		tmp =- 1;
	}
	char* p = strtok(str, "+-");
	if (tmp==-1)
	{
		minus += atoi(p);
	}
	else
	{
		plus += atoi(p);
	}
	
	while (p != NULL)
	{
		p = strtok(NULL, "+-");
		while (i < strlen(str1))
		{
			if (str1[i] == '+')
			{
				if (tmp == -1)
					minus += atoi(p);
				else
					plus += atoi(p);
				i++;
				break;
			}
			else if(str1[i]=='-')
			{
				tmp = -1;
				minus += atoi(p);
				i++;
				break;
			}
			i++;
		}
	}
	int result = plus - minus;
	printf("%d\n", result);
	return 0;
}