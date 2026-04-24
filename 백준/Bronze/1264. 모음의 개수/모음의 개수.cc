#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main(void)
{
	char str[257];
	char shap[2] = "#";
	int count;
	while (1)
	{
		count = 0;
		fgets(str, 257, stdin);
		str[strlen(str) - 1] = '\0';
		if (strcmp(str, shap) == 0)
			break;
		else
		{
			for (int i = 0; i < strlen(str); i++)
			{
				if (str[i] == 'a' || str[i] == 'A' || str[i] == 'o' || str[i] == 'O' || str[i] == 'e' || str[i] == 'E' || str[i] == 'i' || str[i] == 'I' || str[i] == 'u' || str[i] == 'U')
					count++;
			}
			printf("%d\n", count);
		}
	}
	return 0;
}