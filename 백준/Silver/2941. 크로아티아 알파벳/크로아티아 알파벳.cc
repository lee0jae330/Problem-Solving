#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main(void)
{
	char str[105];
	scanf("%s", str);
	int len = strlen(str);
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == 'c' || str[i] == 'd' || str[i] == 'l' || str[i] == 'n' || str[i] == 's' || str[i] == 'z')
		{
			if (str[i] == 'c')
			{
				if (str[i + 1] == '=' || str[i+1] == '-')
					len--;
			}
			else if (str[i] == 'd')
			{
				if (str[i + 1] == '-')
				{
					len--;
				}
				else if (str[i + 1] == 'z')
				{
					if (str[i + 2] == '=')
						len--;
				}
			}
			else if (str[i] == 'l')
			{
				if (str[i + 1] == 'j')
					len--;
			}
			else if (str[i] == 'n')
			{
				if (str[i + 1] == 'j')
					len--;
			}
			else if (str[i] == 's')
			{
				if (str[i+1] == '=')
					len--;
			}
			else if (str[i] == 'z')
			{
				if (str[i+1] == '=')
					len--;
			}
		}
	}
	printf("%d\n", len);
	return 0;
}