#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	char str[3] = "";
	fgets(str, 3, stdin);
	str[2] = '\0';
	if (str[0] == 'A')
	{
		if (str[1] == '+')
			printf("4.3\n");
		if (str[1] == '0')
			printf("4.0\n");
		if (str[1] == '-')
			printf("3.7\n");
	}
	if (str[0] == 'B')
	{
		if (str[1] == '+')
			printf("3.3\n");
		if (str[1] == '0')
			printf("3.0\n");
		if (str[1] == '-')
			printf("2.7\n");
	}
	if (str[0] == 'C')
	{
		if (str[1] == '+')
			printf("2.3\n");
		if (str[1] == '0')
			printf("2.0\n");
		if (str[1] == '-')
			printf("1.7\n");
	}
	if (str[0] == 'D')
	{
		if (str[1] == '+')
			printf("1.3\n");
		if (str[1] == '0')
			printf("1.0\n");
		if (str[1] == '-')
			printf("0.7\n");
	}
	if (str[0] == 'F')
		printf("0.0\n");
	return 0;
}